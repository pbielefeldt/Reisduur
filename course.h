#ifndef COURSE_H
#define COURSE_H

/* Kurs-Bestimmung. Wird aus einem Config-File gebaut, das so aussieht:
 *   Name | Latitude | Longitude
 *
 * Wobei der Name ein freier, aber einzigartiger (!) Parameter ist,
 * Lat und Lon sind in Dezimal-Grad angegeben, also z.B.
 *   SPORT-A,52.96667,5.16667
 */

#include <QWidget>

#include <QString>
#include <QFile>
#include <QList>
#include <QStringList>

#include <iostream>

class Course
{
public:
    Course();
    Course(QString BuoysFile);

    // Liste der Namen aller Tonnen
    const QStringList getNames(){return fNames;}

    double Bearing(QString Tonne_1, QString Tonne_2);
    double Distance(QString Tonne_1, QString Tonne_2);

private:

    // Schaut nach dem Tonnennamen und gibt ggf. den [Lat, Lon] Vektor
    QList <double> Position(QString BName);

    // Enthaelt alle Tonnenpositionen als array
    // ACHTUNG: Die Lon & Lat sind als QString! Und in Grad!
    QList <QStringList> fBuoys;
    QStringList fNames;

};

#endif // COURSE_H
