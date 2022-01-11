#ifndef TOY_H
#define TOY_H

#include <string>
#include "Product.h"
/* ======================================
    TODO: Complete the class declaration of Toy
    HINT: remember to take the structure figure in the lab website page as reference
   ======================================*/

class Toy:public Product{
    private:
    string character;
    string manufacturer;
    public:
    Toy(double regular_price,const string& character, const string& manufacturer);
    virtual ~Toy();

    string get_character() const;
    string get_manufacturer() const;
    void print() const override;
};
#endif