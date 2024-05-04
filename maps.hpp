/*  # # #   # # #  # # #  # # # #       # # # #     #       #        # # #   # # # #
  #     # #     # #    # #             #    # #   #        #       # * * #  #
 #       #     # #    # # # # #       # # #   # #         #       #  *  #  #  # # #
#     # #     # #    # #             #    #   #          #       # * * #  #      #
# # #   # # #  # # #  # # # #       # # #    #          # # # #  # # #    # # # # */

#ifndef MAPS_H
#define MAPS_H

#include <vector>
#include <QString>

class Maps
{
private:
    QString _mapName; //Название карты
    std::vector<QString> positions; //Позиции на карте
    std::vector<QString> paths; //Пути к видео

public:
    Maps();
    ~Maps();

    void clearVectors(); //Очистка векторов

    //Заполнение векторов
    void de_anubis();
    void de_inferno();
    void de_vertigo();
    //void de_mirage();
    //void de_ancient();
    //void de_dust2();
    //void de_nuke();


    std::vector<QString> getPositions(); //Получить массив позиций
    std::vector<QString> getPaths(); //Получить массив путей
    QString getMapName(); //Получить название карты
};

#endif //MAPS_H
