#include <iostream>
using namespace std;

int main(){
    int a = 1 , b= 2, c= 3;
    auto f = [&](int x) {a*=x; b+=x; c=a+b;};
    
}