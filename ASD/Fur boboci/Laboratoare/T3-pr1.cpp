#include <iostream>
#include <fstream>

using namespace std;

struct Nod{
    int info;
    Nod *leg;
};

void Add_Sort(Nod *&L, int x)
{
    Nod *p,*q,*r;
    q=new Nod;
    q->info=x;
    q->leg=NULL;

    if(L==NULL) L = q;

    else
    {
        if(L->leg==NULL)
        {
            if (x<L->info)
            {
                q->leg = L;
                L = q;
            }
            else
            {
                L->leg = q;
            }
        }
        else
        {
            p=L;
            cout<<"aaa  "<<p->info<<"\n\n\n";
            while(p->leg!=NULL && p->leg->info<x)
            {
                r=p;
                p=p->leg;
                cout<<"hhhh\n";
            }
            cout<<"bbb  "<<p->info<<"\n\n\n";
            if(p!=NULL)
            {
                q->leg=p->leg;
                p->leg=q;
            }
            /*else
            {
                r->leg=q;
                q->leg=NULL;
            }*/
        }
    }
}

void Citire(Nod *&L)
{
    int x;
    ifstream fin("date.in");
    while(fin>>x)
        Add_Sort(L,x);
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
