#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <QString>
#include <QVariant>
#include <QMessageBox>
#include <random>
#include <ctime>
using namespace std;

class Game
{
public:
    Game();
    QString *generate_number();
    void generate_order(int amount);
    bool game_compare(int button, int circle);
    int *order;
    ~Game();
private:
    default_random_engine randomEngine;
    int getRandom(int start, int end);
};

#endif // GAME_H
