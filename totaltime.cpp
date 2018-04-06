#include "totaltime.h"

TotalTime::TotalTime()
{
    fData.clear();
    Empty="Noch kein Eintrag.";

}

void TotalTime::addLap(QString &Name, double &Time/*, bool refresh=true*/){

    QStringList strList;
    strList << Name << QString::number(Time);
    fData.push_back(strList);

//    if (refresh) this->refresh();
}

void TotalTime::purge(){
    fData.clear();
//    this->refresh();
}

//void TotalTime::refresh(){

//}

QString TotalTime::getTotalTimeStr(){

    QString re;

    if (fData.size()==0){
        re = Empty;
        return re;
    }

    QList< QStringList >::iterator i;
    for (i = fData.begin(); i != fData.end(); ++i){
        re.append((*i).join(":\t \t"));
        re.append("\n");
    }

    return re;
}

double TotalTime::getTotalTime(){

    double re=0.;

    QList< QStringList >::iterator i;
    for (i = fData.begin(); i != fData.end(); ++i){
        re += (*i).at(1).toDouble();
    }

    return re;
}
