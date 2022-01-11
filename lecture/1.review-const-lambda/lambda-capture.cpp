#include <iostream>
using namespace std;
int main(){
    int sum = 0, a= 1, b= 2, c=3;
    
    for(int k = 0; k<4; ++k){
        cout << [=](int x){return a*x*x ;}(k) << endl;
    }
    int f;
    cout << (f = [&](int g =2){return b*=g;}()) << endl;

    
 
}