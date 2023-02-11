#include <iostream>
#include <fstream>

using namespace std;

struct Pol{
    int gr, coef;
    Pol *leg;
};

Pol *P;
int n,k;

void Add(Pol *&P, int x, int y)
{
    Pol *p;
    p=new Pol;
    p->gr=x;
    p->coef=y;
    p->leg=P;
    P=p;
}

void Citire()
{
    int i,y;
    ifstream fin("date.in");
    fin>>n>>k;
    for(i=0;i<n;i++)
    {
        fin>>y;
        Add(P,n-i-1,y);
    }
}

void Afisare(Pol *P)
{
    Pol *p;
    p=P;
    while(p!=NULL)
    {
        cout<<p->coef<<"*x^"<<p->gr<<"\n";
        p=p->leg;
    }
    cout<<"\n\n\n";
}

void Solve()
{
    Pol *p;
    p=P;
    while(p!=NULL)
    {
        p->coef=p->coef*k;
        p=p->leg;
    }
}

int main()
{
    P=NULL;
    Citire();
    Afisare(P);
    Solve();
    Afisare(P);
    return 0;
}

