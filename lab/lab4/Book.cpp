#include <iostream>
#include "Book.h"

using namespace std;

// TODO: complete the constructor of Book
Book::Book(double regular_price, const string& title, 
    const string& genre, const string& publisher, double discount):Product(regular_price),title(title),
        genre(genre),publisher(publisher),discount(discount){}
Book::~Book() {
    cout << "Book destructed" <<endl;
}
// TODO: complete Book::get_title
string Book::get_title() const{
    return this->title;
}
// TODO: complete Book::get_genre
string Book::get_genre() const{
    return this->genre;
}
// TODO: complete Book::get_publisher
string Book::get_publisher() const{
    return this->publisher;
}
// TODO: complete Book::get_discount
double Book::get_discount() const {
    return this->discount;;
}
// TODO: complete Book::get_retail_price
double Book::get_retail_price() const {
   // print();
    return this->get_regular_price()*discount;
}
void Book::print() const{
    cout<<"Book: "<<endl;
    cout << "Title: "<<get_title() << ", Genre: " <<get_genre() << ", Publisher: " << get_publisher() << ", Retail Price: " << get_retail_price()<<endl;
}