#ifndef TOTALTIME_H
#define TOTALTIME_H

#include <QString>
#include <QList>
#include <QStringList>

class TotalTime
{
public:
    TotalTime();

    void addLap(QString& Name, double &Time);
    void purge();
//    void refresh();

    QString getTotalTimeStr();
    double getTotalTime();

private:
    QList < QStringList > fData;
    QString Empty;
};

#endif // TOTALTIME_H
