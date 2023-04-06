#include "Car.h"
#include <string>

using namespace std;

int Car::counter = 0;
char Car::board[MAX_WIDTH][MAX_HEIGHT] = {0};

Car::Car(){
  
}

Car::Car(int x, int y, char alignment){
  Car::counter++;
  this->id = Car::counter;
  this->x = x;
  this->y = y;
  this-> alignment = alignment;
  Car::board[x][y] = this->id;
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

string Car::getAction() const{
  return this->actionName;
}

void Car::setX(int x){
  this->x = x;
}

void Car::setY(int y){
  this->y = y;
}

void Car::setPrevious(Car* c){
  this->prev = c;
}

void Car::setAction(string action){
  this->actionName = action;
}

void Car::setObstacle(int x, int y){
  Car::board[x][y] = -1;
}

bool Car::isFree(int x, int y) const{
  return Car::board[x][y] != -1;
}

bool Car::goUp(Car &c){
  if (this->alignment == 'v'){
    bool flag = false;
    for (int i = this->y; i<MAX_HEIGHT; i++){
      if (!isFree(this->x, i)){
        flag = true;
      }
    }
    if (flag) return false;
    else{
      Car::board[this->x][this->y] = 0;
      c.setPrevious(this);
      string temp = "Το αυτοκίνητο με ID ";
      temp.append(1, this->id + '0');
      temp.append(" μετακινήθηκε προς τα πάνω και αφαιρέθηκε");
      c.setAction(temp);
      return false;
    }
  }
  return false;
}

bool Car::goDown(Car &c){
  if (this->alignment == 'v'){
    bool flag = false;
    for (int i = 0; i<this->y; i++){
      if (!isFree(this->x, i)){
        flag = true;
      }
    }
    if (flag) return false;
    else{
      Car::board[this->x][this->y] = 0;
      c.setPrevious(this);
      string temp = "Το αυτοκίνητο με ID ";
      temp.append(1, this->id + '0');
      temp.append(" μετακινήθηκε προς τα κάτω και αφαιρέθηκε");
      c.setAction(temp);
      return false;
    }
  }
  return false;
}

bool Car::goLeft(Car &c){
  if (this->alignment == 'o'){
    bool flag = false;
    for (int i = this->x; i<MAX_WIDTH; i++){
      if (!isFree(i, this->y)){
        flag = true;
      }
    }
    if (flag) return false;
    else{
      Car::board[this->x][this->y] = 0;
      c.setPrevious(this);
      string temp = "Το αυτοκίνητο με ID ";
      temp.append(1, this->id + '0');
      temp.append(" μετακινήθηκε προς τα αριστερά και αφαιρέθηκε");
      c.setAction(temp);
      return false;
    }
  }
  return false;
}

bool Car::goRight(Car &c){
  if (this->alignment == 'o'){
    bool flag = false;
    for (int i = 0; i<this->x; i++){
      if (!isFree(x, this->y)){
        flag = true;
      }
    }
    if (flag) return false;
    else{
      Car::board[this->x][this->y] = 0;
      c.setPrevious(this);
      string temp = "Το αυτοκίνητο με ID ";
      temp.append(1, this->id + '0');
      temp.append(" μετακινήθηκε προς τα δεξιά και αφαιρέθηκε");
      c.setAction(temp);
      return false;
    }
  }
  return false;
}

vector <Car *> Car::expand(){
   vector <Car *> children;
    Car *child;
    child = new Car(*this);
    if (goUp(*child))
        children.push_back(child);
    else
        delete child;
    child = new Car(*this);
    if (goDown(*child))
        children.push_back(child);
    else
        delete child;
    child = new Car(*this);
    if (goLeft(*child))
        children.push_back(child);
    else
        delete child;
    child = new Car(*this);
    if (goRight(*child))
        children.push_back(child);
    else
        delete child;
    child = new Car(*this);
  
    return children;
}

bool Car::operator == (const Car &c) const{
  return (this->x == c.x && this->y == c.y && this->alignment == c.alignment);
}
