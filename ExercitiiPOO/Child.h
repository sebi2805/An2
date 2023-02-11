#ifndef child
#define child
#include <iostream>
#include <vector>
#include <memory>
#include "BToy.h"
enum class ChildType
{
    cuuminte,
    neascultator
};
class Child
{
    std::string adresa, nume, prenume;
    int varsta, numarFapteBune;
    ChildType tip;
    int chestiiExtra;
    std::vector<std::shared_ptr<BToy>> jucarii;
    static int idCopil;

public:
    Child(std::string nume = "undefined", std::string prenume = "undefined", std::string adresa = "undefined", int varsta = 0, int numarFapteBune = 0);
    Child(Child &);
    virtual void print(std::ostream &) const;
    virtual void read(std::istream &);
    friend std::ostream &operator<<(std::ostream &, Child &);
    friend std::istream &operator>>(std::istream &, Child &);
    bool searchByName(std::string &);
    int getVarsta() const { return varsta; }
    int getFapte() const { return numarFapteBune; }
};
#endif