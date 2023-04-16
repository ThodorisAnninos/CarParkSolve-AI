#ifndef CAR_H
#define CAR_H

#include <string>
#include <vector>
#include "Board.h"

using namespace std;

class Car {
  static int counter;
  
  private:
    char id, alignment;
    int x, y;

  public:
    Car();
    Car(int x, int y, char alignment, Board &b);


    int getID() const;
    char getAlignemnt() const;
    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);
    
    
    bool goUp(Board *b);
    bool goDown(Board *b);
    bool goLeft(Board *b);
    bool goRight(Board *b);

    friend ostream &operator<< (ostream &mystream, const Car &c);
};



#endif