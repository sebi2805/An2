#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
using namespace std;
class B{
        int b;
public: B(int p=1){b=p;}
};
class D: public B{
         int *d;
 public: D(int p){d=new int; *d=p;}
         D(const D& s):B(s){d=new int; d=(s.d);}
         void set(int p){*d=p;}
};

int main()
{D o1(2),o2(o1);
 o1=o2;o2.set(4);
return 0;
}