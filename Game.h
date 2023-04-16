#ifndef GAME_H
#define GAME_H

#include "Car.h"
#include "Board.h"
#include <vector>
#include <string>

using namespace std;

class Game{
  private:
    vector<Car *> cars;
    Board* board;
    Game* prev;
    string action;

    void removeCar(Car *c);
  public:
    Game();
    Game(const Game& other);
    Game(Board *b, vector<Car*> cars);

    string getAction() const;
    Board* getBoard();
    int getDepth();
    Game * getPrevious();

    void setBoard(Board *b);
    void setPrevious(Game* g);
    void setAction(string action);

    vector <Game *> expand();

    bool operator == (const Game &c) const;
};

#endif