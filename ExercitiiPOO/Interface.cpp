#include <iostream>
#include <algorithm>
#include <vector>
#include "Interface.h"
void Interface::start()
{
          int i = 1;
          while (i)
          {
                    try
                    {

                              std::cout << "Ce actiube vreti sa efectuati\n1.Adaugarea a n copii\n2.Cautati un copil dupa nume si afisati datele\n3.Sa ordoneze copii dupa faptele lor\n5.Afisarea tuturor copiilor\n6.Afisare raport\n7.Sa se ordoneze copii dipa varsta" << std::endl;
                              std::cin >> i;
                              switch (i)
                              {
                              case 1:

                              {
                                        int j;
                                        std::shared_ptr<Child> aux;
                                        std::cout
                                            << "Cati copii vreti sa adaugati" << std::endl;
                                        std::cin >> j;
                                        for (int k = 0; k < j; k++)
                                        {
                                                  aux = std::make_shared<Child>();
                                                  std::cin >> *aux;
                                                  // aux->read(std::cit)
                                                  copii.push_back(aux);
                                        }
                                        break;
                              }
                              case 2:
                              {
                                        std::string aux;
                                        std::cout << "Ce nume cautati?" << std::endl;
                                        std::cin >> aux;
                                        for (auto copil : copii)
                                        {
                                                  if (copil->searchByName(aux))
                                                            std::cout << *copil;
                                        }
                                        break;
                              }
                              case 7:
                              {
                                        std::sort(copii.begin(), copii.end(), [](const std::shared_ptr<Child> &lhs, const std::shared_ptr<Child> &rhs)
                                                  { return lhs->getVarsta() < rhs->getVarsta(); });
                                        break;
                              }
                              case 3:
                              {
                                        std::sort(copii.begin(), copii.end(), [](const std::shared_ptr<Child> &lhs, const std::shared_ptr<Child> &rhs)
                                                  { return lhs->getFapte() < rhs->getFapte(); });
                                        break;
                              }
                              case 5:
                              {
                                        for (auto copil : copii)
                                                  std::cout << *copil;
                                        break;
                              }
                              case 6:
                              {
                                        BToy::printStatics();
                                        break;
                              }
                              default:
                              {
                                        break;
                              }
                              }
                    }
                    catch (...)
                    {
                              std::cout << "An error happened try aggain" << std::endl;
                    }
          };
};
int Interface::comparatorVarsta(std::shared_ptr<Child> &a, std::shared_ptr<Child> &b)
{
          return a->getVarsta() > b->getVarsta();
};
int Interface::comparatorFapte(std::shared_ptr<Child> &a, std::shared_ptr<Child> &b)
{
          return a->getFapte() > b->getFapte();
};