#include "Car.h"
#include <string>
#include <iostream>

using namespace std;

int Car::counter = 0;

Car::Car(){
  
}

Car::Car(int x, int y, char alignment, Board &b){
  Car::counter++;
  this->id = Car::counter;
  this->x = x;
  this->y = y;
  this-> alignment = alignment;
  b.addCarByID(x, y, this->id);
}

int Car::getID() const{
  return (int)this->id;
}

char Car::getAlignemnt() const{
  return this->alignment;
}

int Car::getX() const{
  return this->x;
}

int Car::getY() const{
  return this->y;
}

void Car::setX(int x){
  this->x = x;
}

void Car::setY(int y){
  this->y = y;
}


bool Car::goUp(Board *b){
  if (this->alignment == 'v'){
    for (int i = 0; i<this->y; i++){
      if (!b->isFree(this->x, i)){
        return false;
      }
    }
    return true;
  }
  return false;
}

bool Car::goDown(Board *b){
  if (this->alignment == 'v'){
    for (int i = this->y+1; i<=MAX_HEIGHT; i++){
      if (!b->isFree(this->x, i)){
        return false;
      }
    }
      return true;
  }
  return false;
}

bool Car::goLeft(Board *b){
  if (this->alignment == 'o'){
    for (int i = 0; i<this->x; i++){
      if (!b->isFree(i, this->y)){
        return false;
      }
    }
    return true;
  }
  return false;
}

bool Car::goRight(Board *b){
  if (this->alignment == 'o'){
    for (int i = this->x+1; i<=MAX_WIDTH; i++){
      if (!b->isFree(i, this->y)){
        return false;
      }
      return true;
    }
  }
  return false;
}

ostream &operator<< (ostream &mystream, const Car &c){
  mystream<<"Car ID: "<<c.getID()<<", x = "<<c.getX()<<", y = "<<c.getY()<<", Alignment: ";
  if (c.getAlignemnt() == 'o')
    mystream<<"Horizontal";
  else
    mystream<<"Vertical";
  mystream<<endl;
  return mystream;
}

