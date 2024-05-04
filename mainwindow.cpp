#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("CS2 Nades");

    setLabelText();
    setStatusBarText();

    //s_window = new secondwindow();

//    secondwindow s_window;

//    connect(this, &MainWindow::setSecondWindowName, &s_window, &secondwindow::setThisWindowName);
//    connect(this, &MainWindow::setMap, &s_window, &secondwindow::setMap);
}

MainWindow::~MainWindow()
{
//    delete s_window;
//    s_window = nullptr;

    delete ui;
    ui = nullptr;
}

void MainWindow::setLabelText()
{
    ui->label->setStyleSheet("QLabel"
    "{"
        "color: #666666;"
        "text-align: center;"
    "}");

    ui->label->setAlignment(Qt::AlignCenter & Qt::AlignHCenter);

    ui->label->setText("<i>Created by <b>LOG</b></i><br>v" NADES_VERSION);
}

void MainWindow::setStatusBarText()
{
    ui->statusbar->setStyleSheet("QStatusBar {color: #666666; font-style: italic}");
    ui->statusbar->showMessage("Связь с разработчиком: log.plusplus@gmail.com");
}

void MainWindow::on_de_anubis_clicked()
{
    QString secondWindowTitle = "Anubis nades";
    QString mapName = "Anubis";

    execSecondWindow(secondWindowTitle, mapName);
}

void MainWindow::on_de_inferno_clicked()
{
    QString secondWindowTitle = "Inferno nades";
    QString mapName = "Inferno";

    execSecondWindow(secondWindowTitle, mapName);
}

void MainWindow::on_de_vertigo_clicked()
{
    QString secondWindowTitle = "Vertigo nades";
    QString mapName = "Vertigo";

    execSecondWindow(secondWindowTitle, mapName);
}

void MainWindow::execSecondWindow(QString &_secondWindowTitle, QString &_mapName)
{
    //s_window->setModal(true);

    secondwindow s_window;

    connect(this, &MainWindow::setSecondWindowName, &s_window, &secondwindow::setThisWindowName);
    connect(this, &MainWindow::setMap, &s_window, &secondwindow::setMap);

    //s_window.setModal(true);

    emit setSecondWindowName(_secondWindowTitle);
    emit setMap(_mapName);

    s_window.exec();

    //s_window->show();
}

void MainWindow::on_actionchangelog_triggered()
{
    QMessageBox::information(this, "Changelog", "Version " NADES_VERSION "\n"
    "\n- Добавлена карта Vertigo"
    "\n- Изменена функция просмотра изменений (changelog)"
    "\n- Мелкие изменения");
}
