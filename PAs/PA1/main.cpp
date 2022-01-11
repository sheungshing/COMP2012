#include <iostream>
#include "decimal.h"

using namespace std;

int main()
{
    int testCase = 1;

    while(true){
    cout << "Please enter the test case number: ";
    cin >> testCase;
    cout << endl;

    cout << "============================================" << endl;
    cout << "Showing the output for test case " << testCase << ":" << endl;

    if(testCase == 1) //test the default constructor
    {
        Decimal* zero = new Decimal;
        zero->print();
        cout << endl;
        delete zero;
    }

    else if(testCase == 2) //test the conversion constructor
    {
        Decimal* zero = new Decimal("0");
        zero->print();
        cout << endl;
        delete zero;
    }
    else if(testCase == 3) //test the conversion constructor
    {
        Decimal* d = new Decimal("123456789876543212345678987654321");
        d->print();
        cout << endl;
        delete d;
    }
    else if(testCase == 4) //test the conversion constructor
    {
        Decimal* d = new Decimal("-123456789876543212345678987654321.132134513513123213312123123312312141244");
        d->print();
        cout << endl;
        delete d;
    }
    else if(testCase == 5) //test the conversion constructor
    {
        Decimal* d = new Decimal("3.141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415");
        d->print();
        cout << endl;
        delete d;
    }

    else if(testCase == 6) //test the conversion constructor
    {
        Decimal* d = new Decimal(0);
        d->print();
        cout << endl;
        delete d;
    }
    else if(testCase == 7) //test the conversion constructor
    {
        Decimal* d = new Decimal(1234);
        d->print();
        cout << endl;
        delete d;
    }
    else if(testCase == 8) //test the conversion constructor
    {
        Decimal* d = new Decimal(-987);
        d->print();
        cout << endl;
        delete d;
    }
    else if(testCase == 9) //test the conversion constructor
    {
        Decimal* d = new Decimal(-12344321);
        d->print();
        cout << endl;
        delete d;
    }

    else if(testCase == 10) //test countDigitsBeforeDP and countDigitsAfterDP
    {
        Decimal* d = new Decimal("3.14");
        cout << "The number is ";
        d->print();
        cout << endl;
        cout << "countDigitsBeforeDP = " << d->countDigitsBeforeDP() << endl;
        cout << "countDigitsAfterDP = " << d->countDigitsAfterDP() << endl;
        delete d;
    }
    else if(testCase == 11) //test countDigitsBeforeDP and countDigitsAfterDP
    {
        Decimal* d = new Decimal("-378.1");
        cout << "The number is ";
        d->print();
        cout << endl;
        cout << "countDigitsBeforeDP = " << d->countDigitsBeforeDP() << endl;
        cout << "countDigitsAfterDP = " << d->countDigitsAfterDP() << endl;
        delete d;
    }
    else if(testCase == 12) //test countDigitsBeforeDP and countDigitsAfterDP
    {
        Decimal* d = new Decimal("78");
        cout << "The number is ";
        d->print();
        cout << endl;
        cout << "countDigitsBeforeDP = " << d->countDigitsBeforeDP() << endl;
        cout << "countDigitsAfterDP = " << d->countDigitsAfterDP() << endl;
        delete d;
    }
    else if(testCase == 13) //test countDigitsBeforeDP and countDigitsAfterDP
    {
        Decimal* d = new Decimal();
        cout << "The number is ";
        d->print();
        cout << endl;
        cout << "countDigitsBeforeDP = " << d->countDigitsBeforeDP() << endl;
        cout << "countDigitsAfterDP = " << d->countDigitsAfterDP() << endl;
        delete d;
    }

    else if(testCase == 14) //test isNegative
    {
        Decimal* a = new Decimal("12.345");
        cout << "Is 12.345 negative? ";
        cout << boolalpha << a->isNegative();
        cout << endl;
        delete a;
    }
    else if(testCase == 15) //test isNegative
    {
        Decimal* a = new Decimal("-12.345");
        cout << "Is -12.345 negative? ";
        cout << boolalpha << a->isNegative();
        cout << endl;
        delete a;
    }
    else if(testCase == 16) //test isNegative
    {
        Decimal* a = new Decimal("-0.1");
        cout << "Is -0.1 negative? ";
        cout << boolalpha << a->isNegative();
        cout << endl;
        delete a;
    }
    else if(testCase == 17) //test isNegative
    {
        Decimal* a = new Decimal();
        cout << "Is 0 negative? ";
        cout << boolalpha << a->isNegative();
        cout << endl;
        delete a;
    }

    else if(testCase == 18) //test flipSign
    {
        Decimal* a = new Decimal("12.345");
        cout << "Flip 12.345: ";
        a->flipSign().print();
        cout << endl;
        delete a;
    }
    else if(testCase == 19) //test flipSign
    {
        Decimal* a = new Decimal("-12.345");
        cout << "Flip -12.345: ";
        a->flipSign().print();
        cout << endl;
        delete a;
    }
    else if(testCase == 20) //test flipSign
    {
        Decimal* a = new Decimal("0");
        cout << "Flip 0: ";
        a->flipSign().print();
        cout << endl;
        delete a;
    }
    else if(testCase == 21) //test flipSign
    {
        Decimal* a = new Decimal("-9");
        cout << "Flip -9: ";
        a->flipSign().print();
        cout << endl;
        delete a;
    }

    else if(testCase == 22) //test isLargerThan
    {
        Decimal* a = new Decimal("12.345");
        Decimal* b = new Decimal("12.345");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 23) //test isLargerThan
    {
        Decimal* b = new Decimal("12.345");
        Decimal* a = new Decimal("13.345");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 24) //test isLargerThan
    {
        Decimal* b = new Decimal("12.345");
        Decimal* a = new Decimal("-31.345");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 25) //test isLargerThan
    {
        Decimal* b = new Decimal("12.345");
        Decimal* a = new Decimal("12.945");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 26) //test isLargerThan
    {
        Decimal* b = new Decimal("-12.345");
        Decimal* a = new Decimal("-12.349");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 27) //test isLargerThan
    {
        Decimal* b = new Decimal("12.345");
        Decimal* a = new Decimal("9.345");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 28) //test isLargerThan
    {
        Decimal* b = new Decimal("12.9");
        Decimal* a = new Decimal("12.345");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 29) //test isLargerThan
    {
        Decimal* b = new Decimal("12.3451");
        Decimal* a = new Decimal("12.345");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 30) //test isLargerThan
    {
        Decimal* b = new Decimal("0");
        Decimal* a = new Decimal("100");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 31) //test isLargerThan
    {
        Decimal* b = new Decimal("0.1");
        Decimal* a = new Decimal("0.01415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514150000000000000000000000001");
        a->print();
        cout << " > ";
        b->print();
        cout << " ? ";
        cout << boolalpha << a->isLargerThan(*b);
        cout << endl;
        b->print();
        cout << " > ";
        a->print();
        cout << " ? ";
        cout << boolalpha << b->isLargerThan(*a);
        cout << endl;
        delete a;
        delete b;
    }



    else if(testCase == 32) //test add
    {
        Decimal* a = new Decimal("123412312312312.123");
        Decimal* b = new Decimal("87546687450968405968");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 33) //test add
    {
        Decimal* a = new Decimal("12000000000141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415000000000");
        Decimal* b = new Decimal("6001415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514150000000000000000");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 34) //test add
    {
        Decimal* a = new Decimal("12");
        Decimal* b = new Decimal("6.78");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 35) //test add
    {
        Decimal* a = new Decimal("12.345");
        Decimal* b = new Decimal("6");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 36) //test add
    {
        Decimal* b = new Decimal("12.999999999999999999141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415999999999999999999999999999999999999345");
        Decimal* a = new Decimal("6.99991415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514159999999999999999999999999999999999999999999999999978");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 37) //test add
    {
        Decimal* b = new Decimal("12");
        Decimal* a = new Decimal("6");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 38) //test add
    {
        Decimal* b = new Decimal("12");
        Decimal* a = new Decimal("6.78");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 39) //test add
    {
        Decimal* b = new Decimal("12.345");
        Decimal* a = new Decimal("6");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 40) //test add
    {
        Decimal* a = new Decimal("-12.345");
        Decimal* b = new Decimal("12.345");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 41) //test add
    {
        Decimal* b = new Decimal("-12.345");
        Decimal* a = new Decimal("12.345");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 42) //test add
    {
        Decimal* a = new Decimal("-98.919");
        Decimal* b = new Decimal("2.34");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 43) //test add
    {
        Decimal* b = new Decimal("-98.919");
        Decimal* a = new Decimal("2.34");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 44) //test add
    {
        Decimal* b = new Decimal("-98.919");
        Decimal* a = new Decimal("-2.34");
        a->print();
        cout << " + ";
        b->print();
        cout << " = ";
        a->add(*b).print();
        cout << endl;
        delete a;
        delete b;
    }


    else if(testCase == 45) //test addToSelf
    {
        Decimal* a = new Decimal("12.345");
        Decimal* b = new Decimal("6");
        a->addToSelf(*b);
        cout << "a has been updated to ";
        a->print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 46) //test addToSelf
    {
        Decimal* a = new Decimal("141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415");
        Decimal* b = new Decimal("0.999999999999999999999999999912312213213312123123");
        a->addToSelf(*b);
        cout << "a has been updated to ";
        a->print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 47) //test addToSelf
    {
        Decimal* a = new Decimal("0");
        Decimal* b = new Decimal("0");
        a->addToSelf(*b);
        cout << "a has been updated to ";
        a->print();
        cout << endl;
        delete a;
        delete b;
    }


    else if(testCase == 48) //test deep copy
    {
        Decimal* a = new Decimal("12");
        Decimal* c = new Decimal(*a);
        cout << "a is "; a->print(); cout << endl;
        cout << "c (deep copy of a) is "; c->print(); cout << endl;
        delete a;
        cout << "after deleting a, c (deep copy of a) is "; c->print(); cout << endl;
        delete c;
        cout << "both deleted. no crash! wow. amaze." << endl;
    }
    else if(testCase == 49) //test deep copy
    {
        Decimal* a = new Decimal("12838128973892173891273912837.12938712983712398129837218937129837123");
        Decimal* c = new Decimal(*a);
        cout << "a is "; a->print(); cout << endl;
        cout << "c (deep copy of a) is "; c->print(); cout << endl;
        delete a;
        cout << "after deleting a, c (deep copy of a) is "; c->print(); cout << endl;
        delete c;
        cout << "both deleted. no crash! wow. amaze." << endl;
    }
    else if(testCase == 50) //test deep copy
    {
        Decimal* a = new Decimal();
        Decimal* c = new Decimal(*a);
        cout << "a is "; a->print(); cout << endl;
        cout << "c (deep copy of a) is "; c->print(); cout << endl;
        delete a;
        cout << "after deleting a, c (deep copy of a) is "; c->print(); cout << endl;
        delete c;
        cout << "both deleted. no crash! wow. amaze." << endl;
    }


    else if(testCase == 51) //test timesTenPower
    {
        Decimal* a = new Decimal("12.345");
        a->print();
        cout << " * 10 = ";
        a->multiplyByPowerOfTen(1).print();
        cout << endl;
        delete a;
    }
    else if(testCase == 52) //test timesTenPower
    {
        Decimal* a = new Decimal("-0.345");
        a->print();
        cout << " * 10000 = ";
        a->multiplyByPowerOfTen(4).print();
        cout << endl;
        delete a;
    }
    else if(testCase == 53) //test timesTenPower
    {
        Decimal* a = new Decimal("12345141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415");
        a->print();
        cout << " * 100 = ";
        a->multiplyByPowerOfTen(2).print();
        cout << endl;
        delete a;
    }
    else if(testCase == 54) //test timesTenPower
    {
        Decimal* a = new Decimal("-12345.000000000000000000000000012345");
        a->print();
        cout << " * 1000000000000 = ";
        a->multiplyByPowerOfTen(12).print();
        cout << endl;
        delete a;
    }
    else if(testCase == 55) //test timesTenPower
    {
        Decimal* a = new Decimal();
        a->print();
        cout << " * 1000000000000 = ";
        a->multiplyByPowerOfTen(12).print();
        cout << endl;
        delete a;
    }


    else if(testCase == 56) //test multiplyBySingleDigit
    {
        Decimal* a = new Decimal("12");
        a->print();
        cout << " * 2 = ";
        a->multiplyBySingleDigit(2).print(); 
        cout << endl;
        delete a;
    }
    else if(testCase == 57) //test multiplyBySingleDigit
    {
        Decimal* a = new Decimal("-0.345141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415");
        a->print();
        cout << " * 3 = ";
        a->multiplyBySingleDigit(3).print();
        cout << endl;
        delete a;
    }
    else if(testCase == 58) //test multiplyBySingleDigit
    {
        Decimal* a = new Decimal("12.345");
        a->print();
        cout << " * 9 = ";
        a->multiplyBySingleDigit(9).print(); 
        cout << endl;
        delete a;
    }
    else if(testCase == 59) //test multiplyBySingleDigit
    {
        Decimal* a = new Decimal();
        a->print();
        cout << " * 9 = ";
        a->multiplyBySingleDigit(9).print(); 
        cout << endl;
        delete a;
    }
    else if(testCase == 60) //test multiplyBySingleDigit
    {
        Decimal* a = new Decimal("716238721637812637123687123621378612388127638761283");
        a->print();
        cout << " * 0 = ";
        a->multiplyBySingleDigit(0).print(); 
        cout << endl;
        delete a;
    }
    else if(testCase == 61) //test multiplyBySingleDigit
    {
        Decimal* a = new Decimal("716238721637812637123687123621378612388127638761283");
        a->print();
        cout << " * 9 = ";
        a->multiplyBySingleDigit(9).print(); 
        cout << endl;
        delete a;
    }



    else if(testCase == 62) //test multiply
    {
        Decimal* a = new Decimal("12.345");
        Decimal* b = new Decimal("6.78");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 63) //test multiply
    {
        Decimal* a = new Decimal("12");
        Decimal* b = new Decimal("6");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 64) //test multiply
    {
        Decimal* a = new Decimal("12");
        Decimal* b = new Decimal("6.78");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 65) //test multiply
    {
        Decimal* a = new Decimal("12.345");
        Decimal* b = new Decimal("6");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 66) //test multiply
    {
        Decimal* b = new Decimal("12.3");
        Decimal* a = new Decimal("6.7");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 67) //test multiply
    {
        Decimal* b = new Decimal("12");
        Decimal* a = new Decimal("6");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 68) //test multiply
    {
        Decimal* b = new Decimal("-12141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415");
        Decimal* a = new Decimal("-6.78");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 69) //test multiply
    {
        Decimal* b = new Decimal("12.345");
        Decimal* a = new Decimal("-6141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 70) //test multiply
    {
        Decimal* b = new Decimal("12999999999999999999999999999999999.999999999999999999999999999999999345");
        Decimal* a = new Decimal("-9999999999999999999999999999999996");
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 71) //test multiply
    {
        Decimal* b = new Decimal("12999999999999999999999999999999999.999999999999999999999999999999999345");
        Decimal* a = new Decimal();
        a->print();
        cout << " * ";
        b->print();
        cout << " = ";
        a->multiply(*b).print();
        cout << endl;
        delete a;
        delete b;
    }


    else if(testCase == 72) //test subtract
    {
        Decimal* a = new Decimal("56.78");
        Decimal* b = new Decimal("21.43");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 73) //test subtract
    {
        Decimal* a = new Decimal("56.78");
        Decimal* b = new Decimal("29.99");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 74) //test subtract
    {
        Decimal* a = new Decimal("156.78");
        Decimal* b = new Decimal("21.43");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 75) //test subtract
    {
        Decimal* a = new Decimal("56.781");
        Decimal* b = new Decimal("29.99");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 76) //test subtract
    {
        Decimal* b = new Decimal("56.78");
        Decimal* a = new Decimal("21.43");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 77) //test subtract
    {
        Decimal* b = new Decimal("56.78");
        Decimal* a = new Decimal("29.99");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 78) //test subtract
    {
        Decimal* b = new Decimal("156.78");
        Decimal* a = new Decimal("21.43");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 79) //test subtract
    {
        Decimal* b = new Decimal("56.781");
        Decimal* a = new Decimal("29.99");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 80) //test subtract
    {
        Decimal* b = new Decimal();
        Decimal* a = new Decimal("29123213123213312123312123.9999999999999999999999999999999999999999999999999991");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 81) //test subtract
    {
        Decimal* b = new Decimal("-56.781");
        Decimal* a = new Decimal("29.99");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 82) //test subtract
    {
        Decimal* b = new Decimal("-56.781");
        Decimal* a = new Decimal("-29.99");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 83) //test subtract
    {
        Decimal* a = new Decimal("0");
        Decimal* b = new Decimal("999999999999999999999999999999998141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }
    else if(testCase == 84) //test subtract
    {
        Decimal* b = new Decimal("0");
        Decimal* a = new Decimal("0.999999999999999999999999999999998141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415141514151415");
        a->print();
        cout << " - ";
        b->print();
        cout << " = ";
        a->subtract(*b).print();
        cout << endl;
        delete a;
        delete b;
    }



    cout << "============================================" << endl << endl;
    }
    return 0;
}
