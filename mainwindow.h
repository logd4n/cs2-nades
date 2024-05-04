/*  # # #   # # #  # # #  # # # #       # # # #     #       #        # # #   # # # #
  #     # #     # #    # #             #    # #   #        #       # * * #  #
 #       #     # #    # # # # #       # # #   # #         #       #  *  #  #  # # #
#     # #     # #    # #             #    #   #          #       # * * #  #      #
# # #   # # #  # # #  # # # #       # # #    #          # # # #  # # #    # # # # */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>

#include "secondwindow.h"

#define NADES_VERSION "0.2.0 alpha"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void execSecondWindow(QString &secondWindowTitle, QString &mapName);
    void setLabelText();
    void setStatusBarText();

private slots:
    void on_de_anubis_clicked();

    void on_de_inferno_clicked();

    void on_actionchangelog_triggered();

    void on_de_vertigo_clicked();

private:
    Ui::MainWindow *ui{};
    //secondwindow s_window;

signals:
    void setSecondWindowName(QString &secondWindowTitle);
    void setMap(QString &mapName);

};
#endif // MAINWINDOW_H
