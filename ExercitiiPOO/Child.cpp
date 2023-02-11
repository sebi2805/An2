
#include <iostream>
#include "Child.h"
#include "Clasice.h"
#include "Educative.h"
#include "Electronice.h"
#include "Moderne.h"
int Child::idCopil = 0;
Child::Child(std::string nume, std::string prenume, std::string adresa, int varsta, int numarFapteBune)
    : nume(nume), prenume(prenume), adresa(adresa), numarFapteBune(numarFapteBune)
{
    idCopil++;
};
void Child::print(std::ostream &os) const
{
    os << "Numele copilul este " << nume << " prenumel copilului este " << prenume << "varsta copilului este" << varsta
       << " adresa copilului este " << adresa << " numarul de fapte bune este " << numarFapteBune << std::endl;
    if (tip == ChildType::cuuminte)
        os << "Copilul a fost cuminte si are " << chestiiExtra << "dulciuri" << std::endl;
    else
        os << "Copilul a fost neascultator si are " << chestiiExtra << " carbuni " << std::endl;
    for (auto jucarie : jucarii)
    {
        jucarie->print(os);
    }
};
void Child::read(std::istream &is)
{
    std::cout << "Care este numele copilului?" << std::endl;
    is >> nume;
    std::cout << "Care este prenumele copilului?" << std::endl;
    is >> prenume;
    std::cout << "Care este adresa copilului?" << std::endl;
    is >> adresa;
    std::cout << "Care este varsta copilului?" << std::endl;
    is >> varsta;
    int i;
    std::cout << "Cum a fost copilul?\n 1.Cuminte\n2.Neascultator" << std::endl;
    is >> i;
    switch (i)
    {
    case 1:
    {
        tip = ChildType::cuuminte;
        break;
    }
    case 2:
    {
        tip = ChildType::neascultator;
        break;
    }
    default:
    {
        throw "Acest tip de copil nu exista";
        break;
    }
    }
    std::cout << "Care este numarul de fapte bune are copilului?" << std::endl;
    is >> numarFapteBune;
    while (tip == ChildType::cuuminte && numarFapteBune < 10)
    {
        std::cout << "Un copil cuminte trb sa aiba peste 10 fapte bune" << std::endl;
        std::cout << "Care este numarul de fapte bune are copilului?" << std::endl;
        is >> numarFapteBune;
    }
    if (tip == ChildType::cuuminte)
    {
        std::cout << "Introduceti un numar de bomboane" << std::endl;
        is >> chestiiExtra;
    }
    else
    {
        std::cout << "Introduceti un numar de carbuni" << std::endl;
        is >> chestiiExtra;
    };
    for (int i = 0; i < numarFapteBune / 10; i++)
    {
        int j;
        std::shared_ptr<BToy> aux;
        std::cout << "Ce fel de jucari vreti sa introduceti?\n1.Clasica\n2.Educative\n3.Electronica\n4.Moderna" << std::endl;
        std::cin >> j;

        switch (j)
        {
        case 1:
        {
            aux = std::make_shared<Clasice>();
            aux->read(std::cin);
            jucarii.push_back(aux);
            break;
        }
        case 2:
        {
            aux = std::make_shared<Educative>();
            aux->read(std::cin);
            jucarii.push_back(aux);
            break;
        }
        case 3:
        {
            aux = std::make_shared<Electronice>();
            aux->read(std::cin);
            jucarii.push_back(aux);
            break;
        }
        case 4:
        {
            aux = std::make_shared<Moderne>();
            aux->read(std::cin);
            jucarii.push_back(aux);
            break;
        }
        default:
            break;
        }
    }
};
Child::Child(Child &obj)
{
    nume = obj.nume;
    adresa = obj.adresa;
    prenume = obj.prenume;
    jucarii = obj.jucarii;
    varsta = obj.varsta;
    numarFapteBune = obj.numarFapteBune;
};
std::ostream &operator<<(std::ostream &os, Child &obj)
{
    obj.print(os);

    return os;
};
std::istream &operator>>(std::istream &is, Child &obj)
{
    obj.read(is);
    return is;
};
bool Child::searchByName(std::string &_nume)
{

    if (nume.find(_nume) != std::string::npos || prenume.find(_nume)) //
        return true;
    return false;
};