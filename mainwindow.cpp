#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //---- Set Up Classes ----//
    myCourse = new Course("./Data/Buoys.csv");
    myPolar = new PolarDiagramm("./Data/Polar.csv");
    myTTWidget = new TotalTime();


    //---- Fill in forms ----//
    this->setUpBoxes(myCourse);
    ui->Input_WindDir->setText("0.");
    ui->Input_TWS->setText("0.");
    ui->Label_Laps->setText(myTTWidget->getTotalTimeStr());

    //---- Signals ----//
    // Wenn eine der beiden Boxen geandert wird, wird das Ergebnis neu berechnet
    connect(ui->Box_Start, SIGNAL(currentIndexChanged(int)), this, SLOT(updateResult()));
    connect(ui->Box_Finish, SIGNAL(currentIndexChanged(int)), this, SLOT(updateResult()));
    connect(ui->Button_Update, SIGNAL(clicked(bool)), this, SLOT(updateResult()));
    connect(ui->Button_Alter, SIGNAL(clicked(bool)), this, SLOT(alterPoints()));

    connect(ui->Button_Plus, SIGNAL(clicked(bool)), this, SLOT(addLap()));
    connect(ui->Button_SumClear, SIGNAL(clicked(bool)), this, SLOT(clearTT()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpBoxes(QStringList Names){
    ui->Box_Start->addItems(Names);
    ui->Box_Finish->addItems(Names);
}

void MainWindow::setUpBoxes(Course* myCourse){
    this->setUpBoxes(myCourse->getNames());
}

void MainWindow::updateResult(){

    QString Start = ui->Box_Start->currentText();
    QString Finish = ui->Box_Finish->currentText();

    double WindDir = ui->Input_WindDir->text().toDouble();
    double TrueWind = ui->Input_TWS->text().toDouble();

    double Bearing = myCourse->Bearing(Start, Finish);
    double Distanz = myCourse->Distance(Start, Finish);
    double twa = Bearing-WindDir;
    double Geschwindigkeit = myPolar->speed(twa, TrueWind);
    double t = Distanz/Geschwindigkeit;

//    std::cout << "Bearing:         " << Bearing <<          " degree"   << std::endl;
//    std::cout << "True Wind Angle: " << twa <<              " degree"   << std::endl;
//    std::cout << "Distanz:         " << Distanz <<          " nmi"      << std::endl;
//    std::cout << "Geschwindigkeit: " << Geschwindigkeit <<  " knots"    << std::endl;

//    std::cout << "Von Tonne " << Start.toStdString() << " nach " << Finish.toStdString() << " braucht man " << t << " Stunden. " << std::endl;

    ui->Label_Result->setText(QString("%1").arg(t, 0, 'f', 3));
}

void MainWindow::addLap(){
    QString Lap = ui->Box_Start->currentText();
    Lap.append(" -> ");
    Lap.append(ui->Box_Finish->currentText());

    double Time = ui->Label_Result->text().toDouble();

    myTTWidget->addLap(Lap,Time);

    ui->Label_Laps->setText(myTTWidget->getTotalTimeStr());
    ui->Label_TotalTime->setText(QString("%1").arg(myTTWidget->getTotalTime(), 0, 'f', 2));
}

void MainWindow::clearTT(){
    myTTWidget->purge();
    ui->Label_Laps->setText(myTTWidget->getTotalTimeStr());
    ui->Label_TotalTime->setText("0");
}

void MainWindow::alterPoints(){
    int StartOld = ui->Box_Start->currentIndex();
    int FinishOld = ui->Box_Finish->currentIndex();

    ui->Box_Start->setCurrentIndex(FinishOld);
    ui->Box_Finish->setCurrentIndex(StartOld);

    this->updateResult();
}
