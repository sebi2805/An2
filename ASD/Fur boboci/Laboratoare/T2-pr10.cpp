#include <iostream>
#include <fstream>

using namespace std;

struct Pol{
    int gr, coef;
    Pol *leg;
};

Pol *P,*Q,*T;
int n,m;

void Add(Pol *&R, int x, int y)
{
    Pol *p;
    p=new Pol;
    p->gr=x;
    p->coef=y;
    p->leg=R;
    R=p;
}

void Citire()
{
    int i,y;
    ifstream fin("date.in");
    fin>>n>>m;
    for(i=0;i<=n;i++)
    {
        fin>>y;
        Add(P,n-i,y);
    }
    for(i=0;i<=m;i++)
    {
        fin>>y;
        Add(Q,m-i,y);
    }
}

void Afisare(Pol *R)
{
    Pol *p;
    p=R;
    while(p!=NULL)
    {
        cout<<p->coef<<"*x^"<<p->gr<<"\n";
        p=p->leg;
    }
    cout<<"\n\n\n";
}

void Solve(Pol *R, Pol *S)
{
    int i,x;
    Pol *p,*q;
    p=P;
    q=S;
    i=0;
    while(p!=NULL && q!=NULL)
    {
        x=p->coef + q->coef;
        Add(T,i,x);
        i++;
        p=p->leg;
        q=q->leg;
    }

    while(p!=NULL)
    {
        Add(T,i,p->coef);
        i++;
        p=p->leg;
    }

    while(q!=NULL)
    {
        Add(T,i,q->coef);
        i++;
        q=q->leg;
    }
}

int main()
{
    P=NULL;
    Q=NULL;
    T=NULL;
    Citire();
    Afisare(P);
    Afisare(Q);
    Solve(P,Q);
    Afisare(T);
    return 0;
}

