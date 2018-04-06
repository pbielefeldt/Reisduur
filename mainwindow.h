#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

#include "course.h"
#include "polardiagramm.h"
#include "totaltime.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Course* myCourse;
    PolarDiagramm* myPolar;
    TotalTime* myTTWidget;

    // Nimmt die Tonnen-Namen des Kurses und baut sie in die Boxen ein
    void setUpBoxes(QStringList Names);
    void setUpBoxes(Course *myCourse);

private slots:

    void updateResult();
    void addLap();
    void clearTT();
    void alterPoints();
};

#endif // MAINWINDOW_H
