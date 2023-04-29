#include "Board.h"
#include <iostream>
#include <sstream>

using namespace std;

Board::Board(){
  for (int i = 0; i<MAX_HEIGHT; i++)
    for (int j = 0; j<MAX_WIDTH; j++)
      board[i][j] = 0;
}

void Board::setBoard(char b[MAX_HEIGHT][MAX_WIDTH]){
  for(int i = 0; i < MAX_HEIGHT; i++)
    for (int j= 0; j<MAX_WIDTH; j++)
      board[i][j] = b[i][j];
}

char * Board::getBoard(){
  return *this->board;
}

void Board::setObstacle(int x, int y){
  board[y][x] = -1;
}

void Board::addCarByID(int x, int y, int ID){
  board[y][x] = (char)ID;
}

void Board::setFree(int x, int y){
  board[y][x] = 0;
}

bool Board::isFree(int x, int y){
  return board[y][x] == 0;
}

bool Board::hasCar(int x, int y){
  return board[y][x] != 0 && board[y][x] != -1;
}

void Board::getGoalBoard(char board[MAX_HEIGHT][MAX_WIDTH], char goal[MAX_HEIGHT][MAX_WIDTH]){
  for (int i=0; i<MAX_HEIGHT; i++){
    for (int j=0; j<MAX_WIDTH; j++){
      goal[i][j] = board[i][j] > 0 ? 0 : board[i][j];
    }
  }
}


void Board::printBoard(){
  for (int i=0; i<MAX_HEIGHT; i++){
    for (int j=0; j<MAX_WIDTH; j++){
      stringstream c;
      switch(board[i][j]){
        case -1: c<<'X'; break;
        case 0: c<<' '; break;
        default: c<<(int)board[i][j]; break;
      }
      cout<<"|\t"<<c.str()<<"\t";
    }
  cout<<"|"<<endl;
  }
  cout<<endl;
}