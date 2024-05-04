#include "maps.hpp"

Maps::Maps(){};

Maps::~Maps()
{
    clearVectors();
}

void Maps::clearVectors()
{
    //Очищаем векторы
    positions.clear();
    paths.clear();
}

std::vector<QString> Maps::getPositions()
{
    return positions;
}

std::vector<QString> Maps::getPaths()
{
    return paths;
}

QString Maps::getMapName()
{
    return _mapName;
}

void Maps::de_anubis()
{
    clearVectors();

    _mapName = "Anubis";

    positions = {"Смок на А дефолт (T)", "Смок на А лестницу (steirs) (T)", "Смок на плато (хелпа-девятка) (T)",
    "Смок на девятку (хэвен) (T)", "Смок на окно 1 (T)", "Смок на мид 1 (T)", "Смок на мид 2 (T)",
    "Смок на паласы (T)", "Смок на backsite (T)", "Смок на аллею (T)"};

    paths = {"a_t_default.mp4", "a_t_stairs.mp4", "a_t_plateau.mp4",
    "a_t_heaven.mp4", "t_window_1.avi", "t_middle_1.mp4", "t_middle_2.mp4",
    "b_t_palace.mp4", "b_t_backsite_1.mp4", "b_t_alley_1.mp4"};
}

void Maps::de_inferno()
{
    clearVectors();

    _mapName = "Inferno";

    positions = {"Смок на лонг 1 (T)", "Смок на лонг 2 (T)", "Смок на лонг 3 (T)", "Смок на лонг 4 (CT/T)",
    "Смок на лонг 5 (T)", "Смок на лонг 6 (T)", "Смок на малые пески (T)", "Смок в яму (T)",
    "Смок на шорт 1 (T)", "Смок на шорт 2 (T)", "Смок на шорт 3 (T)", "Смок на банан 1 (CT)",
    "Смок на крыло (порч) (CT)", "Смок на Б фонтан (CT)", "Смок на тачку (T)", "Смок на гробы 1 (T)",
    "Смок на гробы 2 (T)", "Смок на ct 1 (T)"};

    paths = {"a_t_long_1.mp4", "a_t_long_2.mp4", "a_t_long_3.mp4", "a_long_4.mp4",
    "a_t_long_5.mp4", "a_t_long_6.mp4", "a_t_moto.mp4", "a_t_pit.mp4",
    "a_t_short_1.mp4", "a_t_short_2.mp4", "a_t_short_3.mp4", "b_ct_banana_1.mp4",
    "b_ct_porch.mp4", "b_ct_site.mp4", "b_t_car.mp4", "b_t_coffin_1.mp4",
    "b_t_coffin_2.mp4", "b_t_ct_1.mp4"};
}

void Maps::de_vertigo()
{
    clearVectors();

    _mapName = "Vertigo";

    positions = {"Смок на ct 1 (T)", "Смок на мейн 1 (T)", "Смок на мейн 2 (T)", "Смок на elevator 1 (T)",
    "Смок на stairs 1 (CT)"};

    paths = {"b_t_ct_1.mp4", "b_t_main_1.mp4", "b_t_main_2.mp4", "b_t_elevator_1.mp4",
    "b_ct_stairs_1.mp4"};
}
