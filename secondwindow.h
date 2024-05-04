/*  # # #   # # #  # # #  # # # #       # # # #     #       #        # # #   # # # #
  #     # #     # #    # #             #    # #   #        #       # * * #  #
 #       #     # #    # # # # #       # # #   # #         #       #  *  #  #  # # #
#     # #     # #    # #             #    #   #          #       # * * #  #      #
# # #   # # #  # # #  # # # #       # # #    #          # # # #  # # #    # # # # */

#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QGraphicsVideoItem>
#include <QDebug>
#include <QCloseEvent>
#include <thread>
#include <chrono>

#include "maps.hpp"

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();

    void playVideo(QUrl &url);
    float getVideoScale();
    void setVideoScale(float scale);
    void inline fillingListWidget();
    //void closeEvent(QCloseEvent*);

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_playButton_clicked(); //Play button

    void on_pauseButton_clicked(); //Pause button

    void on_greaterScale_clicked();

    void on_lessScale_clicked();

public slots:
    void setThisWindowName(QString &windowTitle);
    void setMap(QString &mapName);

private:
    Ui::secondwindow *ui{};
    QMediaPlayer *player{};
    QGraphicsVideoItem *videoItem{};
    QGraphicsScene *scene{};
    Maps *maps{};
    float videoScale{};
};

#endif // SECONDWINDOW_H
