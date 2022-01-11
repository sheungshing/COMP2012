#include <iostream>
#include <cstring>
using namespace std;

// class MyArray{
//    private:
//       int* p;
//       int n;
//    public:
//       MyArray(int n){
//          p = new int[n];
//          this->n = n;
//       }
//       MyArray(const MyArray& aa){
//          p = new int[aa.n];
//          n = aa.n;
//          for(int i=0; i<0; i++){
//             p[i] = aa.p[i];
//          }
//          cout << "copy" << endl;
//       }
//       MyArray haha(){
//          MyArray a(*this);
//          return a;
//       }

//       MyArray& operator=(const MyArray& hehe){
//          p = hehe.p;
//          n = hehe.n;
//          cout << "= is used" << endl;
         
//       }
//       int getN(){ 
//          return n;
//       }
// };
// class Haha{
//    public:
//       Haha w(){cout<<"gg"<< endl;}
// };

// class Hehe{
//    public:
//       void sayHehe(){cout << "hehe" << endl;}
//       void sayHehe() const {cout << "Hehe const" << endl;}
// };

// class  Wow{
//    private:
//       int a;
//    public:
//       Wow(int a) : a(a){}

//    int getA(){
//       return a;
//    }

//    ~Wow(){
//       cout << "delete " << endl;
//    }
// };

int main(){
   // MyArray arr1(5);
   // MyArray arr2 (10);
   // arr2 = arr1;
   // cout << arr2.getN();

   // char* p = new char[10];
   // strcpy(p,"desmond");
   // cout << reinterpret_cast<void*>(p) << endl;

   // Hehe const g;
   // g.sayHehe();
   // g.sayHehe();

   int* p ;
   p = new int [2];
   *p[1] = 20;
  
   cout << *p[0];
}