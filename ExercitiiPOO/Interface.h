#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <memory>
#include "Child.h"
class Interface
{
          std::vector<std::shared_ptr<Child>> copii;

public:
          Interface()
          {
          }
          void start();
          int comparatorVarsta(std::shared_ptr<Child> &a, std::shared_ptr<Child> &b);
          int comparatorFapte(std::shared_ptr<Child> &a, std::shared_ptr<Child> &b);
};
#endif