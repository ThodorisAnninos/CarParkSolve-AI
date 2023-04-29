#include "Game.h"
#include <iostream>
#include <sstream>
using namespace std;

Game::Game(){
  
}

Game::Game(const Game& other){
  this->board = new Board;
  for (int i=0; i<MAX_HEIGHT; i++){
    for (int j=0; j<MAX_WIDTH; j++){
      this->board->board[i][j] = other.board->board[i][j];
    }
  }

  this->cars = vector<Car*>();
  for (int i=0; i<other.cars.size(); i++) {
      this->cars.push_back(other.cars[i]);
  }
}

Game::Game(Board *b, vector<Car*> cars){
  this->board = b;
  this->cars = cars;
}

void Game::setBoard(Board *b){
  for (int i=0; i<MAX_HEIGHT; i++){
    for (int j=0; j<MAX_WIDTH; j++){
      this->board->board[i][j] = b->board[i][j];
    }
  }
}

string Game::getAction() const{
  return this->action;
}

Board* Game::getBoard(){
  return this->board;
}

Game * Game::getPrevious(){
  return this->prev;
}

int Game::getDepth(){
  int counter =0;
    Game *g = this;
    while (g->prev!=nullptr)
    {
        g=g->prev;
        counter++;
    }
    return counter;
}

void Game::setPrevious(Game* g){
  this->prev = g;
}

void Game::setAction(string action){
  this->action = action;
}

void Game::removeCar(Car *c){
  this->board->setFree(c->getX(), c->getY());
  int i=0;
  for (i=0; i<this->cars.size(); i++){
    if (this->cars[i]->getID() == c->getID()){
      break;
    }
  }
  this->cars.erase(cars.begin()+i);
  
}

vector <Game *> Game::expand(){
  vector<Game *>children;
  for (int i=0; i<cars.size(); i++){
    Game * child;
    
    child = new Game(*this);
    if (cars[i]->goUp(this->board)){
      child->removeCar(cars[i]);
      children.push_back(child);
      stringstream stream;
      stream<<"Το αυτοκίνητο με ID "<<cars[i]->getID()<<" μετακινήθηκε προς τα πάνω και αφαιρέθηκε!";
      child->setAction(stream.str());
      child->setPrevious(this);
    } else {
      delete child;
    }

    child = new Game(*this);
    if (cars[i]->goDown(this->board)){
      child->removeCar(cars[i]);
      children.push_back(child);
      stringstream stream;
      stream<<"Το αυτοκίνητο με ID "<<cars[i]->getID()<<" μετακινήθηκε προς τα κάτω και αφαιρέθηκε!";
      child->setAction(stream.str());
      child->setPrevious(this);
    } else {
      delete child;
    }

    child = new Game(*this);
    if (cars[i]->goLeft(this->board)){
      child->removeCar(cars[i]);
      children.push_back(child);
      stringstream stream;
      stream<<"Το αυτοκίνητο με ID "<<cars[i]->getID()<<" μετακινήθηκε προς τα αριστερά και αφαιρέθηκε!";
      child->setAction(stream.str());
      child->setPrevious(this);
    } else {
      delete child;
    }

    child = new Game(*this);
    if (cars[i]->goRight(this->board)){
      child->removeCar(cars[i]);
      children.push_back(child);
      stringstream stream;
      stream<<"Το αυτοκίνητο με ID "<<cars[i]->getID()<<" μετακινήθηκε προς τα δεξιά και αφαιρέθηκε!";
      child->setAction(stream.str());
      child->setPrevious(this);
    } else {
      delete child;
    }

    
  }
  return children;
}

bool Game::operator == (const Game &c) const{
  for (int i=0; i<MAX_HEIGHT; i++){
    for (int j=0; j<MAX_WIDTH; j++){
      if (this->board->board[i][j] != c.board->board[i][j]){
        return false;
      }
    }
  }
  return true;
}