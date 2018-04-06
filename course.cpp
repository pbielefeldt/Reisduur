#include "course.h"

#include <math.h>
#define _USE_MATH_DEFINES

Course::Course()
{
}

Course::Course(QString BuoysFile){

    QFile infile(BuoysFile);
    if (!infile.open(QIODevice::ReadOnly | QIODevice::Text)){
//        std::cerr << "Could not open file " << BuoysFile.toStdString() << std::endl;
        return;
    }

    while (!infile.atEnd()) {
        QString line = infile.readLine();
        QStringList lstLine = line.split(",");
        fBuoys.push_back(lstLine);
        fNames << lstLine.at(0);
    }

    infile.close();

}

double Course::Bearing(QString Tonne_1, QString Tonne_2){

    // Das ist das Initial Bearing, AEnderungen durch den Grosskreis sind
    // nicht beruecksichtig. Sorry.

    QList <double> T1 = this->Position(Tonne_1);
    QList <double> T2 = this->Position(Tonne_2);

    // Get the lat & lon and convert to radiants
    double T1_Lat = T1.at(0)*M_PI/180.;
    double T1_Lon = T1.at(1)*M_PI/180.;
    double T2_Lat = T2.at(0)*M_PI/180.;
    double T2_Lon = T2.at(1)*M_PI/180.;

    double y = sin(T2_Lon-T1_Lon) * cos(T2_Lat);
    double x = cos(T1_Lat)*sin(T2_Lat) - sin(T1_Lat)*cos(T2_Lat)*cos(T2_Lon-T1_Lon);
    double brng = atan2(y, x)*180./M_PI;

    // Das Bearing liegt zwischen 0 degree und +360 degree, entsprechend einem KK
    if (brng<0.) brng = 360+brng;

    return brng;
}

double Course::Distance(QString Tonne_1, QString Tonne_2){
    // Radius der Erde in nmi
    const double R = 3438.1451;

    QList <double> T1 = this->Position(Tonne_1);
    QList <double> T2 = this->Position(Tonne_2);

    double T1_Lat = T1.at(0)*M_PI/180.;
    double T1_Lon = T1.at(1)*M_PI/180.;
    double T2_Lat = T2.at(0)*M_PI/180.;
    double T2_Lon = T2.at(1)*M_PI/180.;

    // Havesine Formel
    return R*acos(sin(T1_Lat)*sin(T2_Lat)+cos(T1_Lat)*cos(T2_Lat)*cos(T1_Lon-T2_Lon));
}

QList <double> Course::Position(QString BName){

//    std::cout << "Name " << BName.toStdString() << std::endl;

    QList <double> re = QList<double>() << 0. << 0.;

    for (int i = 0; i < fBuoys.size(); ++i) {
        if (fBuoys.at(i).at(0) == BName){
            re[0]=fBuoys.at(i).at(1).toDouble(); // Lat
            re[1]=fBuoys.at(i).at(2).toDouble(); // Lon
        }
    }

//    std::cout << "Lat: " << re[0] << " Lon: " << re[1] << std::endl;
    return re;
}
