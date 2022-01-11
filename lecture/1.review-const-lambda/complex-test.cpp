#include <iostream>
using namespace std;

class Complex{
    float real;
    float imag;
    public:
        Complex(float r, float i): real(r),imag(i){}
        
        void print() const{
            cout << "real: " << real << "\timag: "<< imag << endl; 
        }

        Complex add1(const Complex& x){
            real += x.real;
            imag += x.imag;
            return *this;
        }

        Complex* add2(const Complex& x){
            real += x.real;
            imag += x.imag;
            return this;
        }

        Complex& add3(const Complex& x){
            real += x.real;
            imag += x.imag;
            return *this;
        }
};

void f(const Complex a){
    a.print();
}
void g(const Complex* a){
    a->print();
}
void h(const Complex& a){
    a.print();
}

int main(){
    
    Complex bb(4,5);
    f(bb);
    g(&bb);
    h(bb);
    cout << endl;

    Complex w(10,10);
    w.print();
    Complex x(4,5);
    x.add1(w).print();
    Complex y(4,5);
    y.add2(w)->print();
    Complex z(4,5);
    z.add3(w).print();

    cout << endl << endl;

    Complex a(4,5);
    a.add1(w).add1(w).print();
    Complex b(4,5);
    b.add2(w)->add2(w)->print();
    Complex c(4,5);
    c.add3(w).add3(w).print();
   

    
    
    
}