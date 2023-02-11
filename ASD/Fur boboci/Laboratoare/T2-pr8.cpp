#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Nod{
    double info;
    Nod *leg;
};

Nod *L;
int k,n;

void Add(Nod *&L, int x)
{
    Nod *p;
    p=new Nod;
    p->info=x;
    p->leg=L;
    L=p;
}

void Citire()
{
    int i,y;
    ifstream fin("date.in");
    fin>>n>>k;
    for(i=0;i<n;i++)
    {
        fin>>y;
        Add(L,y);
    }
}

void Afisare(Nod *L)
{
    Nod *p;
    p=L;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->leg;
    }
    cout<<"\n";
}

void Solve()
{
    int s;
    double x,i;
    Nod *p;
    p=L;
    i=s=0;
    while(p!=NULL)
    {
        x=pow(k,i);
        x=x*p->info;
        i++;
        s += x;
        p=p->leg;
    }
    cout<<s<<"\n";
}

int main()
{
    L=NULL;
    Citire();
    Afisare(L);
    Solve();
    return 0;
}
