#ifndef BOARD_H
#define BOARD_H

// #define MAX_WIDTH 12
// #define MAX_HEIGHT 10

#define MAX_WIDTH 4
#define MAX_HEIGHT 3

class Board{
  public:
    char board[MAX_HEIGHT][MAX_WIDTH];
  public:
    Board();

    void setBoard(char objs[MAX_HEIGHT][MAX_WIDTH]);
    char *getBoard();

    static void getGoalBoard(char board[MAX_HEIGHT][MAX_WIDTH], char goal[MAX_HEIGHT][MAX_WIDTH]);
    
    void setObstacle(int x, int y);
    void addCarByID(int x, int y, int ID);
    void setFree(int x, int y);

    bool isFree(int x, int y);
    bool hasCar(int x, int y);

    void printBoard();
    
};

#endif