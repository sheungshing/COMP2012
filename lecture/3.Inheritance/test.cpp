#include <iostream>
using namespace std;

class A{
    private:    
    int a;

    public:
    int get_a(){
        return a;
    }
    
    friend class B;
};


class B : public A{
    public:
    void f(){
       A object;
       object.a =20;
       a =20;
    }
};

class C {
    public:
    void g(){
        // A obj;
        // obj.a = 10;
    }
};

int main(){
   B bb;
   bb.f();
   cout << bb.get_a() << endl;
   
}