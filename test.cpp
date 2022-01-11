
// if there is no public, it is automaticlly set to private
/*    class haha{
        public:
        haha(){cout << "haha construtor! " << endl;}
        ~haha(){cout << "haha disconstrutor! "<< endl;}
    };

    class base{
        haha bb;
        public:
        base(){cout << "base construtor!" << endl;};
        ~base(){cout << "base distrutor!" << endl;};
    };

    class derived : public base {
        
        public:
        derived(){cout << "dervied construtor! " << endl;};
        ~derived(){cout << "derived distrutor! "<< endl;};
        };

    int main(){
        derived aa;
    }
*/
/*
    #include <iostream>
    #include <cstring>
    using namespace std;
    class Foo
    {
        public:
            Foo()
    {
    a = new char[9];
    strcpy(a, "comp2012");  //const char*
    c = 100;}

    ~Foo() { delete a; }
    void set_b(int b) { Foo::b = b; }
    void set_c(int c) { this->c{c}; } //this->c= c;
    int get_b() const { return b; }
    int get_c() const { return c; }

    private:
    const char* a;
    int b{10}, c;
    };

    class Bar
    {
    public:
    Bar() { obj = new Foo(); }
    ~Bar() { delete obj; }
    const Foo& get_obj() const { return *obj; }
    void modify(int b) const { obj->set_b(b); }

    private:
    Foo* obj;
    };

    void operate(Bar bar) { bar.modify(10); }

    int main()
    {
    Bar bar;
    Foo* foo = &bar.get_obj(); // bar.get_obJ() reutrns a const object
    operate(bar);
    return 0;
    }
*/

/*
class Word
{
private:
int length = 0; char* str = nullptr;
public:
Word(const char* s) : length(strlen(s)), str(new char [length+1])
{ strcpy(str, s); cout << "convert: "; print(); }
Word(const Word& w) : length(w.length), str(new char [length+1])
{ strcpy(str, w.str); cout << "copy: "; print(); }
Word(Word&& w) : length(w.length), str(w.str)
{ w.length = 0; w.str = nullptr; cout << "move: "; print(); }
~Word() { cout << "~Word: "; print(); delete [] str; }
void print() const
{ cout << (str ? str : "null") << " ; " << length << endl; }
};
class Word_Pair
{
private:
Word w1; Word w2;
public:
Word_Pair(const Word_Pair&) = default;
Word_Pair(Word_Pair&& wp) : w1(std::move(wp.w1)), w2(std::move(wp.w2)) { }
Word_Pair(const Word& a, const Word& b) : w1(a), w2(b)
{ cout << "Call WP1" << endl; }
Word_Pair(Word&& a, Word&& b) : w1(a), w2(b)
{ cout << "Call WP2" << endl; }
};

int main()
{
cout << "(a) *** Print the const names info ***" << endl;
const Word first_name { "Isaac" };
const Word last_name { "Newton" };
Word_Pair name { first_name, last_name };
cout << "\n(b) *** Print the opposites info ***" << endl;
Word_Pair synonym { Word("happy"), Word("sad") };
cout << "\n(c) *** Print the book's info ***" << endl;
Word author { "Orwell" };
Word title { "1984" };
Word_Pair book { Word_Pair(author, title) };
// cout << "\n(d) *** It’s all destructions now ***" << endl;
return 0;
}
*/

/*
int main(){
    int&& x = int();
    int& y = x;
    cout << x;
}
*/

/*
class Car{
    private:
    string brand;
    int age;

    public:
    Car():brand(""),age(1){}
    Car(string bra, int ag):brand(bra),age(ag){}
    //Car(const Car& a){}
    Car operator+(const Car& a){
        this->age+=a.age;
        this->brand = a.brand;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Car& bb){
        os << bb.age <<"\t" << bb.brand << endl;
        return os;
    }
    const Car& operator+=(const Car& bb){
        age+=bb.age;
        brand= bb.brand + " version_2";
        return *this;
    }
    Car& operator++(){
        age++;
        return *this;
    }
    Car operator++(int){
        age++;
        return *this;
    }

    const int getAge()const{
        return age;
    }
    const string getName() const{
        return brand;
    }

};

int main(){
    Car bend("bend",2);
    Car xiaomi("xiaomi",11);
    //xiaomi = xiaomi+bend;
    //cout << xiaomi.getAge() <<"\t" << xiaomi.getName() << endl;
    xiaomi++;
    ++xiaomi;
    cout << xiaomi;
}
*/

/*
template <typename T>
void f(T x, T y) {
cout << "Template" << endl;
}
void f(int x, int y) {
cout << "Non-template" << endl;
}
int main() {
f(1, 2);
f('a', 'b');
f(1, 'b');
}
*/
/*
class Weapon
{
};
class Sword : public Weapon
{
public:
    Sword(int n = 1) { cout << n << " x S" << endl; }
    ~Sword() { cout << "~S" << endl; }
};
class Hero
{
    Weapon *w;

public:
    Hero()
    {
        cout << "H" << endl;
        w = new Weapon;
    }
    ~Hero()
    {
        cout << "~H" << endl;
        delete w;
    }
    virtual const Hero &operator=(const Hero &h) { cout << "H=" << endl; }
};
class SpiderMan : public Hero
{
    Weapon *w;

public:
    SpiderMan()
    {
        cout << "SM" << endl;
        w = new Weapon;
    }
    SpiderMan(const SpiderMan &s)
    {
        cout << "Copy SM" << endl;
        w = new Weapon;
    }
    virtual ~SpiderMan()
    {
        cout << "~SM" << endl;
        delete w;
    }
    const SpiderMan &operator=(const SpiderMan &s) { cout << "SM=" << endl; }
};
class DeadPool : public SpiderMan
{
    Sword sword;

public:
    DeadPool() : sword(2) { cout << "DP" << endl; }
    DeadPool(const DeadPool &d) : SpiderMan(d) { cout << "Copy DP" << endl; }
    ~DeadPool() { cout << "~DP" << endl; }
    const DeadPool &operator=(const DeadPool &d) { cout << "DP=" << endl; }
};
int main()
{
    cout << "--- Block 1 ---" << endl;
    Hero *hero = new DeadPool;
    cout << "--- Block 2 ---" << endl;
    SpiderMan *spiderman = new DeadPool;
    cout << "--- Block 3 ---" << endl;
    DeadPool deadpool(*dynamic_cast<DeadPool *>(spiderman));
    // cout << "--- Block 4 ---" << endl;
    // *hero = *spiderman;
    // cout << "--- Block 5 ---" << endl;
    // delete hero;
    // cout << "--- Block 6 ---" << endl;
    // delete spiderman;
}
*/


// #include <iostream>
// using namespace std;
// class Weapon { };
// class Sword : public Weapon {
// public:
// Sword(int n = 1) { cout << n << " x S" << endl; }
// ~Sword() { cout << "˜S" << endl; }
// };
// class Hero {
// Weapon* w;
// public:
// Hero() { cout << "H" << endl; w = new Weapon; }
// ~Hero() { cout << "˜H" << endl; delete w; }
// virtual const Hero& operator=(const Hero& h) { cout << "H=" << endl; }
// };
// class SpiderMan : public Hero {
// Weapon* w;
// public:
// SpiderMan() { cout << "SM" << endl; w = new Weapon; }
// SpiderMan(const SpiderMan& s) { cout << "Copy SM" << endl; w = new Weapon; }
// virtual ~SpiderMan() { cout << "˜SM" << endl; delete w; }
// const SpiderMan& operator=(const SpiderMan& s) { cout << "SM=" << endl; }
// };
// class DeadPool : public SpiderMan {
// Sword sword;
// Sword sword2;
// public:
// DeadPool(){ cout << "DP" << endl; }
// DeadPool(const DeadPool& d) : SpiderMan(d) { cout << "Copy DP" << endl; }
// ~DeadPool() { cout << "˜DP" << endl; }
// const DeadPool& operator=(const DeadPool& d) { cout << "DP=" << endl; }
// };
// int main() {
// cout << "--- Block 1 ---" << endl;
// Hero* hero = new DeadPool;
// cout << "--- Block 2 ---" << endl;
// SpiderMan* spiderman = new DeadPool;
// cout << "--- Block 3 ---" << endl;
// DeadPool deadpool(*dynamic_cast<DeadPool*>(spiderman));
// cout << "--- Block 4 ---" << endl;
// *hero = *spiderman;
// cout << "--- Block 5 ---" << endl;
// delete hero;
// cout << "--- Block 6 ---" << endl;
// delete spiderman;
// }

#include <iostream>
using namespace std;
int main() {
int a = 10;
[&](int x) mutable { a += x; }(5);
cout << a;
}