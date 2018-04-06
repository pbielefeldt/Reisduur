#include "polardiagramm.h"

PolarDiagramm::PolarDiagramm()
{
}

PolarDiagramm::PolarDiagramm(QString PolarFile){

    QFile InFile(PolarFile);
    if (!InFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        std::cerr << "Could not open file " << PolarFile.toStdString() << std::endl;
        return;
    }

    fMaxTWS = 0;
    fMinTWS = 100;

    while (!InFile.atEnd()) {

        // Individuelle Zeilen einlesen
        QString Line = InFile.readLine();
        QStringList LstLine = Line.split(",");

        // Jede Zeile in einen Vektor konvertieren
        QList<double> v;
        foreach(QString Str, LstLine) {
            v.push_back(Str.toDouble());
        }
        if (v.at(0) > fMaxTWS) fMaxTWS=v.at(0);
        if (v.at(0) < fMinTWS) fMinTWS=v.at(0);
        fData.push_back(v);
    }

    InFile.close();
    
}

double PolarDiagramm::speed(double TWA, double WindGeschw){
    /* Es wird erst nach dem Wendewinkel gesucht.
     * ACHTUNG: Das Programm geht davon aus, dass
     * (a) Der Wendewinkel der kleinste angegebene Winkel fuer die entsprechende
     *     Windgeschwindigkeit ist. Ggf. muss man hier das Polardiagramm fertig-raten...
     * (b) Der Wendewinkel mit zunehmende Windgeschwindigkeit ebenfalls zunimmt.
     *
     * Daher sucht die Funktion erst den True Wind Speed, der kleiner ist als die Wind-
     * geschwindigkeit, sucht dort den kleinsten angegebenen True Wind Angle, und setzt den als
     * Wendewinkel.
     * Fuer den Fall, dass der True Wind Angle t kleiner ist als der Wendewinkel w, verlaengert
     * sie die Strecke um den Faktor f = cos(t)/cos(w).
     * In diesem Fall wird also eigentlich die Distanz d*f mit der Geschwindigkeit am Wendewinkel
     * gefahren; Das entspricht auch der Geschwindigkeit am WW geteilt durch f (die Bezeichnung "VMG"
     * ist hier nicht ganz korrekt, aber so was in der Art ist das eben).
     *
     * Ausserdem gibt es wilde Annahmen, falls die Windgeschwindigkeit ueber oder unter der groessten/
     * kleinsten Geschwindigkeit im PolarFile liegt:.
     */

    // "Negative" Winkel, bzw. Winkel > 180 umrechnen
    if (!(TWA>=0. && TWA<=180.)){

        // Sollte alles symmetrisch sein, ja?!
        if (TWA<0.){
            TWA = -TWA;
//            std::cout << "Negativer twa korrigiert: " << twa << std::endl;
        }

        // Auch symmetrisch um 180 degree
        if (TWA>180.){
            TWA = 360.-TWA;
//            std::cout << "Zu grosser twa korrigiert: " << twa << std::endl;
        }

        // Immer noch nicht? Dann ist was faul!
        if (!(TWA>=0. && TWA<=180.)) return -1.;
    }
//    std::cout << "Korrigierter twa: " << twa << std::endl;

    // Die Windgeschwindigkeiten duerfen nur im Fenster {fMinTWS, fMaxTWS} sein
    double speedCorrectionFactor = 1.;

    // Zu hohe Windgeschwindigkeiten filtern
    if (WindGeschw >= (fMaxTWS-0.01)) {  //TODO: Statt 0.01 was kleineres, das zentral festgelegt ist
        // Hier wird 50% der hohen Geschwindigkeit berechnet
        speedCorrectionFactor = fMaxTWS + (0.5*(WindGeschw-fMaxTWS));  //TODO: Bessere Extrapolation!
        WindGeschw = fMaxTWS-0.01;
    }

    // Zu niedrige Windgeschwindigkeiten filtern
    if (WindGeschw <= (fMinTWS+0.01)){
        speedCorrectionFactor = WindGeschw/(fMinTWS+0.01);
        WindGeschw = fMinTWS+0.01;
    }

//    std::cout << "Wind Speed:       " << WindGeschw << std::endl;
//    std::cout << "Wind correction : " << speedCorrectionFactor << std::endl;

    // Test, ob twa > tackAngle...
    QList<double> Tack = this->tackAngle(WindGeschw);

    if(Tack.at(0) >= TWA){
        double f = cos(TWA*M_PI/180.)/cos(Tack.at(0)*M_PI/180.);
        return Tack.at(1)/f;
    }


    // Erst mal den TWS kleiner und groesser WindGeschw finden!
    double WS_lo = -1;
    double WS_hi = -1;
    bool found = false;

    //TODO: Wie gehen wir mit Windgeschwindigkeiten < kleinster Wind um? Linear interpolieren?

    QList< QList<double> >::iterator i;
    for (i = fData.begin(); i != fData.end(); ++i){
        if ( i->at(0)<WindGeschw ) WS_lo = i->at(0);
        else{
            WS_hi = i->at(0);
            found = true;
            break;
        }
    }
    if (!found){
        std::cerr << "No wind found!" << std::endl;
        return -1;
    }

    // Die beiden Boat Speeds zum Extrapolieren:
    double BS_loWind = this->constWindSpeedV(TWA, WS_lo);
    double BS_hiWind = this->constWindSpeedV(TWA, WS_hi);

    // Normalisierung
    double DeltaWS_lo = WindGeschw-WS_lo;
    double DeltaWS_hi = WS_hi-WindGeschw;

    // Sonderfall: WS ist ein Eintrag in fData => deltaWS_hi=0
    if (DeltaWS_hi == 0) return BS_hiWind;
    if (DeltaWS_lo == 0) return BS_loWind;

    double ReSpeed = ( BS_loWind/DeltaWS_lo + BS_hiWind/DeltaWS_hi ) / (1./DeltaWS_lo + 1./DeltaWS_hi);
    ReSpeed = ReSpeed*speedCorrectionFactor;

//    std::cout << "BS_loWind  " << BS_loWind << "\n" <<
//                 "BS_hiWind  " << BS_hiWind << "\n" <<
//                 "DeltaWS_lo " << DeltaWS_lo << "\n" <<
//                 "DeltaWS_hi " << DeltaWS_hi << std::endl;

//    std::cout << "Speed Calculation: " << ReSpeed << std::endl;

    return ReSpeed;
}

double PolarDiagramm::constWindSpeedV(double TWA, double ConstWindGeschw){

    // Boat Speed, unterhalb und oberhalb des Winkels
    double BTV_lo = -1;
    double BTV_hi = -1;

    // Entsprechende Winkel
    double TWA_lo = -1;
    double TWA_hi = -1;
    double DeltaTWA_lo = -1;
    double DeltaTWA_hi = -1;

    QList< QList<double> >::iterator i;
    for (i = fData.begin(); i != fData.end(); ++i){

        // Springe ueber alle Werte mit zu kleinem TWS
        if ( i->at(0) != ConstWindGeschw ) continue;

        // Angekommen bei TWS==cWindGeschw
        else{
            // Beim Erreichen des TWA wird TWA & BTV geschrieben
            // -- und dann nicht weiter in _lo geschrieben
            if ( i->at(1)>=TWA ) {
                TWA_hi = i->at(1);
                BTV_hi = i->at(2);
                break;
            }
        }

        // Bis zum Erreichen von TWA wird TWS in BTV_lo gespeichert
        TWA_lo = i->at(1);
        BTV_lo = i->at(2);
    }

//    std::cout << "Got BTV_lo " << BTV_lo << " and BTV_hi " << BTV_hi << std::endl;
//    std::cout << "Got TWA_lo " << TWA_lo << " and TWA_hi " << TWA_hi << std::endl;

    // Die eigentliche Berechnung...
    DeltaTWA_lo = TWA-TWA_lo;
    DeltaTWA_hi = TWA_hi-TWA;

    // Sonderfall: Genau einen Winkel getroffen: deltaTWA_hi == 0
    if (DeltaTWA_hi == 0) return BTV_hi;
    if (DeltaTWA_lo == 0) return BTV_lo;

    double v = ( BTV_lo/DeltaTWA_lo + BTV_hi/DeltaTWA_hi ) / (1./DeltaTWA_lo + 1./DeltaTWA_hi);

//    std::cout << "Calculated constant Wind (" << cWindGeschw << " kn) boat speed: " << v << std::endl;
    return v;
}

QList<double> PolarDiagramm::tackAngle(double WindGeschw){

    QList<double> Re = QList<double>() << -1. << -1.;
    double OldA = -1;
    double OldV = -1;
    double OldW = 0;

    // Gehe durch fData, sobald die Windgeschwindigkeit > nullte Spalte (TWS), gib den ersten Eintrag zurueck.
    QList< QList<double> >::iterator i;
    for (i = fData.begin(); i != fData.end(); ++i){
        if (i->at(0) != OldW){
            OldW = i->at(0);
            if (OldW > WindGeschw){
                Re[0]=OldA;
                Re[1]=OldV;
                break;
            }
            else{
                OldA = i->at(1);
                OldV = i->at(2);
                continue;
            }
        }
    }

    return Re;
}
