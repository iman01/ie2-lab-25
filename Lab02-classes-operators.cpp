//don't forget to modify CmakeLists.txt
//add_executable(<PROJECT-NAME> main.cpp Rational.h Rational.cpp)
// ------------------ main.cpp -----------------//
#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
    Rational quarter(1, 4);
    Rational one_third(1, 3);
    Rational some_number(0.35);


    Rational add_result, sub_result;
    add_result = one_third.add(quarter);
    sub_result = one_third.subtract(quarter);
    

    one_third.print(); std::cout << " + "; quarter.print(); std::cout << " = "; add_result.print(); std::cout << std::endl;
    one_third.print(); std::cout << " - "; quarter.print(); std::cout << " = "; sub_result.print(); std::cout << std::endl;
    
    add_result = one_third + quarter; //using oprator overloading
    sub_result = one_third - quarter;
    
    add_result.print();
    sub_result.print();

    cin >> one_third;

    return 0;


}






// ------------------ Rational.hpp -----------------//
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
class Rational {
public:
    Rational(int num = 0, int den = 1); // default constructor
    Rational(double r);



    friend std::ostream &operator<<(std::ostream &str, Rational &rhs);
    void set(int num, int den); // sets numerator and denominator
    int num() const; // gets numerator
    int den() const; // gets denominator
    void set_num(int num); // sets numerator
    void set_den(int den); // sets denominator
    Rational add(const Rational &other) const; // adds second rational number, returns result
    Rational subtract(const Rational &other) const; // subtracts second rational number, returns result
    Rational operator+(const Rational &rhs) const ;

    Rational operator-(const Rational &rhs) const ;

    Rational operator*(const Rational &rhs) const ;
    friend std::istream &operator>>(std::istream &in, Rational &rhs);

    operator double();

//    friend std::istream & operator>>(std::istream &in, Rational &values);


    void print() const; // prints number to console

private:
    int num_, den_;
};



#endif // RATIONAL_H





// ------------------ Rational.cpp -----------------//
#include <iostream>
#include "Rational.h"


using namespace std;


Rational::Rational(int num, int den) : num_(num) { // initializes num_ field with num value
    if (den) {
        den_ = den;
    } else {
        den_ = 1;
    }
}

void Rational::set(int num, int den) {
    num_ = num;
    if (den) {
        den_ = den;
    }
}

Rational::Rational(double r) {
    int den = 1;
    int it = 0;
    while ((r != (int)r)&&(it<9)){
        den *= 10;
        r *= 10;
        it++;
    }
    num_ = r;
    den_ = den;
}

int Rational::num() const {
    return num_;
}

int Rational::den() const {
    return den_;
}

void Rational::set_num(int num) {
    num_ = num;
}

void Rational::set_den(int den) {
    if (den) {
        den_ = den;
    }
}

Rational Rational::add(const Rational &other) const {
    return Rational(num_ * other.den_ + other.num_ * den_,
                    den_ * other.den_);
}

Rational Rational::subtract(const Rational &other) const {
    return Rational(num_ * other.den_ - other.num_ * den_,
                    den_ * other.den_);
}

void Rational::print() const {
    if (den_ == 1) {
        std::cout << num_;
    } else {
        std::cout << num_ << "/" << den_;
    }
}

Rational Rational::operator+(const Rational &rhs) const {
    return Rational(num_ * rhs.den_ + rhs.num_ * den_,
                    den_ * rhs.den_);
}

Rational Rational::operator-(const Rational &rhs) const {
    return Rational(num_ * rhs.den_ - rhs.num_ * den_,
                    den_ * rhs.den_);
}


Rational Rational::operator*(const Rational &rhs) const {
    return Rational(num_ * rhs.num_ ,
                    den_ * rhs.den_);
}

std::istream & operator>>(std::istream &in, Rational &rhs){
        cout << "Enter num Part ";
        in >> rhs.num_;
        cout << "Enter den Part ";
        in >> rhs.den_;
        return in;
}

Rational::operator double(){
    return (double)num_ / (double)den_;
}
