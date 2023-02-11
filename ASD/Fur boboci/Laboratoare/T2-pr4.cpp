#include <iostream>
#include <fstream>

using namespace std;

struct Nod{
    int info;
    Nod *leg;
};


int n,k;

void Init(Nod *&L, int x)
{
    L=new Nod;
    L->info=x;
    L->leg=NULL;
}

void Add(Nod *&L, int x)
{
    Nod *p,*q;
    q=new Nod;
    q->info=x;
    q->leg=NULL;
    if(L==NULL)
        L=q;
    else
    {
        p=L;
        while(p->leg!=NULL)
            p=p->leg;
        p->leg=q;
        q->leg=NULL;
    }
}

void Citire(Nod *&L)
{
    int i,x;
    ifstream fin("date.in");
    fin>>n>>k;
    for(i=0;i<n;i++)
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

void Delete(Nod *&L,Nod *p)
{
    if(p->info==L->info)
    {
        Nod *t=L;
        L=L->leg;
        delete t;
    }
    else
    {
        Nod *t=p->leg;
        p->leg=p->leg->leg;
        delete t;
    }

}

void Solve(Nod *&L, int kk)
{
    int poz=0,ok=0;
    Nod *p;
    p=L;
    while(p!=NULL && ok==0)
    {
        poz++;
        if(poz<kk)
            p=p->leg;
        else
            ok=1;
    }
    cout<<p->info<<"\n";
    Delete(L,p);
}

int main()
{
    Nod *L;
    L=NULL;
    //Init(L,15);
    Citire(L);
    Afisare(L);
    Solve(L,k);
    Afisare(L);
    return 0;
}
