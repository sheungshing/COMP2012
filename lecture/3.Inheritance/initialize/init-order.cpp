#include <iostream>     /* File: init-order.cpp */
using namespace std;

class Address {
  public:
    Address() { cout << "Address's constructor" << endl; }
    ~Address() { cout << "Address's destructor" << endl; }
};

class UPerson { 
  public:
    UPerson() { cout << "UPerson's constructor" << endl; }
    ~UPerson() { cout << "UPerson's destructor" << endl; }
};

class Student : public UPerson { 
  private: 
  Address address;
  
  public:
    Student() { cout << "Student's constructor" << endl; }
    ~Student() { cout << "Student's destructor" << endl; }

  
};

int main() { 
  Student x; 
  return 0; 
  }
