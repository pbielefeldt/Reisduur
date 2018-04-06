#ifndef POLARDIAGRAMM_H
#define POLARDIAGRAMM_H

#include <QWidget>

#include <QString>
#include <QFile>
#include <QList>
#include <QStringList>

#include <iostream>

#include <math.h>
#define _USE_MATH_DEFINES

class PolarDiagramm
{
public:
    PolarDiagramm();
    PolarDiagramm(QString PolarFile);
    /* Ein PolarFile muss folgendermassen aussehen:
	 * TWS/kn | TWA/degree | BTV/kn
	 * 
	 * Die erste Spalte enthaelt den True Wind Speed in knoten, aufsteigend sortiert.
	 * In der zweiten Spalte wird dann der True Wind Angle (in Grad) angegeben, bei 
	 * dem gemessen wurde. Da wir eh nur den Kartenkurs berechnen, brauchen wir auch 
	 * nur den wahren Windwinkel.
	 * Die letzte Spalte beinhaltet den resultierenden Bootsspeed in Knoten.
	 * 
	 * Die Werte werden in fData eingelesen, als array von je drei Eintraegen. 
	 * Folgender Ablauf:
	 *  - Suche Geschwindigkeit kleiner als die angegebene WindGeschw.
	 *    - Zu behandelnde Faelle:
	 *    - WindGeschw < TWS_min => direkt in Qt abfangen?
	 *    - twa kleiner als Wendewinkel => Strecke verlaengern um Faktor XY 
	 *  - Suche twa kleiner als twa in fData
	 *    - Merke Speed und Differenz twa_Boot, twa_fData => BTV/deltaTWA
	 *    - Gehe zum hoeheren twa, gleiche Daten.
	 *    - Bilde gewichtetes Mittel ( BTV_1/deltaTWA_1 + BTV_2/deltaTWA_2 ) / (1/deltaTWA_1 + 1/deltaTWA_2)
	 *    => Funktion constWindSpeedV(Winkel, cWindGeschw)
	 *  - Gleiches fuer naechst hoehere Windgeschwindigkeit in fData
	 *    => Auch gewichtetes Mittel bilden.
	 */

    // Gibt die Geschwindigkeit abhaenging vom Winkel zwischen
    // Boot und Wind (true wind angle) und der Windgeschwindigkeit
    // zurueck
    double speed(double TWA, double WindGeschw);

private:

    // Interpoliert zwischen dem kleinsten Winkel < twa und dem naechst groesseren
    // Fuer die cWindGeschw muss ein Wert aus fData sein!
    double constWindSpeedV(double TWA, double ConstWindGeschw);
    // Der Wendewinkel haengt von der Windgeschwindigkeit ab
    // 0.: TackAngle, 1.: Speed am tA
    QList<double> tackAngle(double WindGeschw);
    
    // Enthaelt das Polardiagramm als array
    QList <QList <double> > fData;

    // Groesster WindSpeed in fData
    double fMaxTWS;

    // Kleinster WindSpeed
    double fMinTWS;
};

#endif // POLARDIAGRAMM_H
