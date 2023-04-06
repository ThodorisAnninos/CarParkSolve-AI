#include <iostream>
#include "Car.h"
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

Car *BFS(Car *initial,Car *goal, long long &examined, long long &mem)
{
    queue<Car *> agenda;
    vector <Car> closed;

    agenda.push(initial);
    examined=0;
    mem=1;
    while (agenda.size()>0)
    {
        if (agenda.size() + closed.size() > mem)
            mem = agenda.size() + closed.size();
        Car *s = agenda.front();
        agenda.pop();
        if (find(closed.begin(), closed.end(), *s)==closed.end())
        {
            examined++;
            if (*s==*goal)
                return s;
            closed.push_back(*s);
            vector<Car *> children =s->expand();
            for (unsigned int i=0;i<children.size();i++)
            {
                if (find(closed.begin(), closed.end(), *children[i])==closed.end())
                    agenda.push(children[i]);
            }
        }
    }
    return nullptr;
}

int main() {
  Car *a = new Car(1, 2, 'o');
  Car *b = new Car(3, 5, 'v');
  cout<<a->getID()<<endl;
  cout<<b->getID()<<endl;
  cout << "Hello World!\n";


  // BFS();
  
  char id = 2;
  string temp = "TESTING: Το αυτοκίνητο με ID ";
  temp.append(1, id+'0');
  temp.append(" μετακινήθηκε προς τα πάνω και αφαιρέθηκε");
  cout<<temp<<endl;
}