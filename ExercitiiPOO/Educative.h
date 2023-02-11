#ifndef EDUCATIVE_H
#define EDUCATIVE_H
#include <iostream>
#include "BToy.h"
class Educative : virtual public BToy
{
    std::string abilitatea;

public:
    Educative(std::string denumire = "undefined", std::string tip = "undefined", int dimensiune = 0, std::string abilitatea = "undefined")
        : BToy(ToyCategory::Educative, denumire, tip, dimensiune), abilitatea(abilitatea){};
    Educative(Educative &);
    void print(std::ostream &) const override;
    void read(std::istream &) override;
    void readSubClass(std::istream &);
    void printSubClass(std::ostream &) const;
    friend std::ostream &operator<<(std::ostream &, Educative &);
    friend std::istream &operator>>(std::istream &, Educative &);
};
#endif