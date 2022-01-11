#include <iostream>
using namespace std;

class Clock             /* File: postoffice2.h */
{
  public:
    Clock()  { cout << "Clock Constructor\n"; }
    ~Clock() { cout << "Clock Destructor\n"; }
};

class Postoffice 
{
    Clock clock;
  public:
    Postoffice() 
        { 
          cout << "good " << endl;
          // clock = new Clock; cout << "Postoffice Constructor\n"; 
          }
    ~Postoffice() { cout << "Postoffice Destructor\n"; }
};


