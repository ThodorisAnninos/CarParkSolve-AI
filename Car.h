#ifndef CAR_H
#define CAR_H

#define MAX_WIDTH 10
#define MAX_HEIGHT 10

#include <string>
#include <vector>
using namespace std;

class Car {
  static int counter;
  static char board[MAX_WIDTH][MAX_HEIGHT];

  private:
    char id, alignment;
    int x, y;
    Car* prev;
    string actionName;

  public:
    Car();
    Car(int x, int y, char alignment);

    int getID() const;
    char getAlignemnt() const;
    int getX() const;
    int getY() const;
    string getAction() const;

    void setX(int x);
    void setY(int y);
    void setPrevious(Car* c);
    void setAction(string action);
    void setObstacle(int x, int y);

    
    bool isFree(int x, int y) const;

    bool goUp(Car &c);
    bool goDown(Car &c);
    bool goLeft(Car &c);
    bool goRight(Car &c);
    vector <Car *> expand();

    bool operator == (const Car &c) const;
};



#endif