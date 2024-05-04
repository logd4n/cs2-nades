#include "secondwindow.h"
#include "./ui_secondwindow.h"

#define DEFAULT_VIDEOSCALE 1.7f //Стандратный размер видео в QGraphicsView
#define MINIMUM_VIDEOSCALE 1.5f //Минимальный размер видео в QGraphicsView
#define MAXIMUM_VIDEOSCALE 3.0f //Максимальный размер видео в QGraphicsView

secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);

    //Инициализирием указатели для работы с видео
    scene = new QGraphicsScene;
    player = new QMediaPlayer();
    videoItem = new QGraphicsVideoItem();

    setVideoScale(DEFAULT_VIDEOSCALE);

    maps = new Maps();
}

secondwindow::~secondwindow()
{
    //Очищаем указатели, чтобы избежать утечки памяти
    delete player;
    player = nullptr;

    delete videoItem;
    videoItem = nullptr;

    delete maps;
    maps = nullptr;

    delete ui;
    ui = nullptr;
}

void secondwindow::setThisWindowName(QString &windowTitle)
{
    setWindowTitle(windowTitle);
}

void secondwindow::setMap(QString &mapName)
{
    ui->listWidget->clear();

    if (mapName == "Anubis")
    {
        maps->de_anubis();

        fillingListWidget();
    }
    else if (mapName == "Inferno")
    {
        maps->de_inferno();

        fillingListWidget();
    }
    else if (mapName == "Vertigo")
    {
        maps->de_vertigo();

        fillingListWidget();
    }
    //else if () ...
    else
    {
        QMessageBox::critical(this, "Ошибка", "Данной карты не существует!");
    }
}

void inline secondwindow::fillingListWidget()
{
    for (size_t i = 0; i < maps->getPositions().size(); i++)
    {
        ui->listWidget->addItem(maps->getPositions().at(i));
    }
}

void secondwindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{    
    QUrl url(QCoreApplication::applicationDirPath() + "/src/Vids/"
    + maps->getMapName() + '/' + maps->getPaths().at(ui->listWidget->currentRow())); //Путь к видео

    ui->label->clear();
    ui->label->setText("Загрузка...");

    qDebug() << url;

    playVideo(url);
}

void secondwindow::playVideo(QUrl &url)
{
    //Воспроизведение видео через GraphicsView
    player->setVideoOutput(videoItem);
    player->setSource(url);
    scene->addItem(videoItem);

    ui->graphicsView->setScene(scene);

    videoItem->setScale(getVideoScale());
    ui->graphicsView->show();
    player->play();
}

void secondwindow::on_playButton_clicked()
{
    player->play();
}

void secondwindow::on_pauseButton_clicked()
{
    player->pause();
}

void secondwindow::on_greaterScale_clicked()
{
    if (getVideoScale() < MAXIMUM_VIDEOSCALE)
    {
        setVideoScale(getVideoScale() + 0.5f);
        videoItem->setScale(getVideoScale());
    }
}

void secondwindow::on_lessScale_clicked()
{
    if (getVideoScale() > MINIMUM_VIDEOSCALE)
    {
        setVideoScale(getVideoScale() - 0.5f);
        videoItem->setScale(getVideoScale());
    }
}

float secondwindow::getVideoScale()
{
    return videoScale;
}

void secondwindow::setVideoScale(float scale)
{
    videoScale = scale;
}

/*
void secondwindow::closeEvent(QCloseEvent *event)
{
    if (QMessageBox::question(this, "Question", "Exit program?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        event->accept();
        secondwindow();
    }
    else
    {
        event->ignore();
    }
}*/
