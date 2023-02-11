#include <iostream>
#include <fstream>

using namespace std;

struct Nod{
    int info;
    Nod *leg;
};

int n;

void Add(Nod *&L, int x)
{
    Nod *p;
    p=new Nod;
    p->info=x;
    p->leg=L;
    L=p;
}

void Citire(Nod *&L)
{
    int i,x;
    ifstream fin("date.in");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x;
        Add(L,x);
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

int main()
{
    Nod *L;
    L=NULL;
    Citire(L);
    Afisare(L);
    return 0;
}
