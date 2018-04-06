#include "mainwindow.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

//    //---- Parameter ----//
//    QString Start   = "SPORT-J";
//    QString Finish  = "SPORT-I";
//    double WindDir  = 195.; // Degree
//    double TrueWind = 12.5; // Knoten

//    //---- Kurs ----//
//    Course* myCourse = new Course("./Data/Buoys.csv");
//    double Bearing = myCourse->Bearing(Start, Finish);
//    double Distanz = myCourse->Distance(Start, Finish);

//    //---- Polar-Diagramm ----//
//    PolarDiagramm* myPolar = new PolarDiagramm("./Data/Polar.csv");
//    double twa = Bearing-WindDir;
//    double Geschwindigkeit = myPolar->speed(twa, TrueWind);

//    //---- Zeit! ----//
//    double t = Distanz/Geschwindigkeit;

//    std::cout << "Bearing:         " << Bearing <<          " degree"   << std::endl;
//    std::cout << "True Wind Angle: " << twa <<              " degree"   << std::endl;
//    std::cout << "Distanz:         " << Distanz <<          " nmi"      << std::endl;
//    std::cout << "Geschwindigkeit: " << Geschwindigkeit <<  " knots"    << std::endl;

//    std::cout << "Von Tonne " << Start.toStdString() << " nach " << Finish.toStdString() << " braucht man " << t << " Stunden. " << std::endl;

    return 0;
}
