#ifndef ELECTRONICE
#define ELECTRONICE
#include <iostream>
#include "BToy.h"
class Electronice : virtual public BToy
{
    int numarBaterii;

public:
    Electronice(std::string denumire = "undefined", std::string tip = "undefined", int dimensiune = 0, int numarBaterii = 1)
        : BToy(ToyCategory::Electronice, denumire, tip, dimensiune), numarBaterii(numarBaterii){};
    Electronice(Electronice &);
    void print(std::ostream &) const override;
    void read(std::istream &) override;
    void readSubClass(std::istream &);
    void printSubClass(std::ostream &) const;
    friend std::ostream &operator<<(std::ostream &, Electronice &);
    friend std::istream &operator>>(std::istream &, Electronice &);
};
#endif