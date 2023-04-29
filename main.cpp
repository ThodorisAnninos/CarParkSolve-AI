#include <iostream>
#include "Car.h"
#include "Board.h"
#include "Game.h"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


Game *BFS(Game *initial,Game *goal, long long &examined, long long &mem)
{
    queue<Game *> agenda;
    vector <Game> closed;

    agenda.push(initial);
    examined=0;
    mem=1;
    while (agenda.size()>0)
    {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        Game *s = agenda.front();
        agenda.pop();
        if (find(closed.begin(), closed.end(), *s)==closed.end())
        {
            examined++;
            if (*s==*goal)
                return s;
          
            closed.push_back(*s);
            vector<Game *> children =s->expand();
            for (unsigned int i=0;i<children.size();i++)
            {
                if (find(closed.begin(), closed.end(), *children[i])==closed.end())
                    agenda.push(children[i]);
            }
        }
    }
    return nullptr;
}



int main(){
  Board *b = new Board;
  Board *b_final = new Board;
  b->setObstacle(3, 0);
  b->setObstacle(0, 1);
  b->setObstacle(2, 2);

  b_final->setObstacle(3, 0);
  b_final->setObstacle(0, 1);
  b_final->setObstacle(2, 2);


  vector<Car *>cars;
  Car *c1 = new Car(2, 0, 'o', *b);
  Car *c2 = new Car(1, 1, 'o', *b);
  Car *c3 = new Car(2, 1, 'v', *b);

  cars.push_back(c1);
  cars.push_back(c2);
  cars.push_back(c3);
  
  cout<<"===Describing the Problem:==="<<endl;
  cout<<"The initial state:"<<endl;
  b->printBoard();
  cout<<"Car Details:"<<endl;
  for (int i=0; i<cars.size();i++)
    cout<<*cars[i];
  cout<<endl;
  cout<<"The goal state:"<<endl;
  b_final->printBoard();
  cout<<endl;

  Game *initial = new Game(b, cars);
  initial->setPrevious(nullptr);
  vector<Car *>cars_empty;
  Game *goal = new Game(b_final, cars_empty);

  Game *solution;
  long long mem,examined;
  solution = BFS(initial, goal, mem, examined);

  cout<<"===Solution:==="<<endl;
  if(solution!=nullptr){
    cout<<"Solution found!"<<endl;
    cout<<"depth = "<<solution->getDepth()<<", Mem: "<<mem<<", Examined: "<<examined<<endl;
    cout<<"The solution in detail:"<<endl;
    Game *g = solution;
    string solution_instructions[solution->getDepth()];
    int i=solution->getDepth();
    while (g->getPrevious()!=nullptr)
    {
      solution_instructions[--i] = g->getAction();
      g=g->getPrevious();
    }
    for (int i=0; i<solution->getDepth(); i++)
      cout<<i+1<<". "<<solution_instructions[i]<<endl;
    
  } else{
    cout<<"Non solvable!";
  }

  cout<<endl<<"Finished!"<<endl;

  
  return 0;
}


// int main(){
//   Board *b = new Board;
//   Board *b_final = new Board;
//   b->setObstacle(1, 1);
//   b->setObstacle(2, 4);
//   b->setObstacle(4, 6);
//   b->setObstacle(7, 3);
//   b->setObstacle(9, 2);
//   b->setObstacle(9, 8);


//   b_final->setObstacle(1, 1);
//   b_final->setObstacle(2, 4);
//   b_final->setObstacle(4, 6);
//   b_final->setObstacle(7, 3);
//   b_final->setObstacle(9, 2);
//   b_final->setObstacle(9, 8);



//   vector<Car *>cars;
//   Car *c1 = new Car(1, 3, 'v', *b);
//   Car *c2 = new Car(1, 6, 'o', *b);
//   Car *c3 = new Car(2, 7, 'v', *b);
//   Car *c4 = new Car(5, 2, 'o', *b);
//   Car *c5 = new Car(7, 0, 'o', *b);
//   Car *c6 = new Car(7, 5, 'v', *b);
//   Car *c7 = new Car(7, 8, 'o', *b);
//   Car *c8 = new Car(8, 6, 'o', *b);
//   Car *c9 = new Car(10, 2, 'o', *b);
//   Car *c10 = new Car(11, 5, 'v', *b);



//   cars.push_back(c1);
//   cars.push_back(c2);
//   cars.push_back(c3);
//   cars.push_back(c4);
//   cars.push_back(c5);
//   cars.push_back(c6);
//   cars.push_back(c7);
//   cars.push_back(c8);
//   cars.push_back(c9);
//   cars.push_back(c10);



  
//   cout<<"===Describing the Problem:==="<<endl;
//   cout<<"The initial state:"<<endl;
//   b->printBoard();
//   cout<<"Car Details:"<<endl;
//   for (int i=0; i<cars.size();i++)
//     cout<<*cars[i];
//   cout<<endl;
//   cout<<"The goal state:"<<endl;
//   b_final->printBoard();
//   cout<<endl;

//   Game *initial = new Game(b, cars);
//   initial->setPrevious(nullptr);
//   vector<Car *>cars_empty;
//   Game *goal = new Game(b_final, cars_empty);

//   Game *solution;
//   long long mem,examined;
//   solution = BFS(initial, goal, mem, examined);

//   cout<<"===Solution:==="<<endl;
//   if(solution!=nullptr){
//     cout<<"Solution found!"<<endl;
//     cout<<"depth = "<<solution->getDepth()<<", Mem: "<<mem<<", Examined: "<<examined<<endl;
//     cout<<"The solution in detail:"<<endl;
//     Game *g = solution;
//     string solution_instructions[solution->getDepth()];
//     int i=solution->getDepth();
//     while (g->getPrevious()!=nullptr)
//     {
//       solution_instructions[--i] = g->getAction();
//       g=g->getPrevious();
//     }
//     for (int i=0; i<solution->getDepth(); i++)
//       cout<<i+1<<". "<<solution_instructions[i]<<endl;
    
//   } else{
//     cout<<"Non solvable!";
//   }

//   cout<<endl<<"Finished!"<<endl;

  
//   return 0;
// }



// int main(){
//   Board *b = new Board;
//   Board *b_final = new Board;
//   b->setObstacle(1, 1);
//   b->setObstacle(2, 4);
//   b->setObstacle(4, 6);
//   b->setObstacle(7, 3);
//   b->setObstacle(9, 2);
//   b->setObstacle(9, 8);


//   b_final->setObstacle(1, 1);
//   b_final->setObstacle(2, 4);
//   b_final->setObstacle(4, 6);
//   b_final->setObstacle(7, 3);
//   b_final->setObstacle(9, 2);
//   b_final->setObstacle(9, 8);



//   vector<Car *>cars;
//   Car *c1 = new Car(1, 3, 'v', *b);
//   Car *c2 = new Car(1, 6, 'o', *b);
//   Car *c3 = new Car(2, 7, 'v', *b);
//   Car *c4 = new Car(5, 2, 'o', *b);
//   Car *c5 = new Car(7, 0, 'o', *b);
//   Car *c6 = new Car(7, 5, 'v', *b);
//   Car *c7 = new Car(7, 8, 'o', *b);
//   Car *c8 = new Car(8, 6, 'o', *b);
//   Car *c9 = new Car(10, 2, 'o', *b);
//   Car *c10 = new Car(11, 5, 'v', *b);
//   Car *c11 = new Car(9, 4, 'v', *b);



//   cars.push_back(c1);
//   cars.push_back(c2);
//   cars.push_back(c3);
//   cars.push_back(c4);
//   cars.push_back(c5);
//   cars.push_back(c6);
//   cars.push_back(c7);
//   cars.push_back(c8);
//   cars.push_back(c9);
//   cars.push_back(c10);
//   cars.push_back(c11);
  
//   cout<<"===Describing the Problem:==="<<endl;
//   cout<<"The initial state:"<<endl;
//   b->printBoard();
//   cout<<"Car Details:"<<endl;
//   for (int i=0; i<cars.size();i++)
//     cout<<*cars[i];
//   cout<<endl;
//   cout<<"The goal state:"<<endl;
//   b_final->printBoard();
//   cout<<endl;

//   Game *initial = new Game(b, cars);
//   initial->setPrevious(nullptr);
//   vector<Car *>cars_empty;
//   Game *goal = new Game(b_final, cars_empty);

//   Game *solution;
//   long long mem,examined;
//   solution = BFS(initial, goal, mem, examined);

//   cout<<"===Solution:==="<<endl;
//   if(solution!=nullptr){
//     cout<<"Solution found!"<<endl;
//     cout<<"depth = "<<solution->getDepth()<<", Mem: "<<mem<<", Examined: "<<examined<<endl;
//     cout<<"The solution in detail:"<<endl;
//     Game *g = solution;
//     string solution_instructions[solution->getDepth()];
//     int i=solution->getDepth();
//     while (g->getPrevious()!=nullptr)
//     {
//       solution_instructions[--i] = g->getAction();
//       g=g->getPrevious();
//     }
//     for (int i=0; i<solution->getDepth(); i++)
//       cout<<i+1<<". "<<solution_instructions[i]<<endl;
    
//   } else{
//     cout<<"Non solvable!";
//   }

//   cout<<endl<<"Finished!"<<endl;

  
//   return 0;
// }
