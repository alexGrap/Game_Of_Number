#include "game.h"

Game::Game(){

    default_random_engine randomEngine(time(NULL));
}

int Game::getRandom(int start, int end)
{
    uniform_int_distribution<int> randomNum( start, end);
    return randomNum(randomEngine);
}

QString *Game::generate_number()
{
    static QString num_array[9];
    for (int i = 0; i < 9; i++)
    {
        QString a = QVariant(getRandom(1,100)).toString();
        for (int j = 0; j < i; j++) {
            if (num_array[j] == a) {
                while (a == num_array[j]) {
                    a = QVariant(getRandom(1,100)).toString();
                }
            }
        }

        num_array[i] = a;
    }
    return num_array;
}

void Game::generate_order(int amount)
{
    int *ord_array = new int(amount);
    srand(time(0));
    for (int i = 0; i < amount; i++)
    {
        ord_array[i] = rand() % 9 + 1;
    }
    order = ord_array;
}

bool Game::game_compare(int button)
{
    for (int i = 0; i < sizeof(order); i++)
    {
        if (order[i] == button) {
            order[i] = 0;
            return true;
        }
    }
    return false;
}

Game::~Game()
{
    delete[] order;
}

