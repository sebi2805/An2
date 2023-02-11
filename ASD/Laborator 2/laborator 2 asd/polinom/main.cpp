#include <iostream>
#include <math.h>
using namespace std;
struct pol{
int gr, coef;
pol *leg;
};
void adaugareSfarsit_coef(pol *&cap,int val)
{
    pol *n=new pol;
    n->leg=NULL;
    n->coef=val;
    if(cap==NULL)
    cap=n;
    else
    {
       pol *aux=cap;
        while(aux->leg!=NULL)
            aux=aux->leg;
    aux->leg=n;
    }
}
void afisare_pol(pol *cap,int i)
{   i--;
    while(cap!=NULL)
    {
        cout<<cap->coef<<"X^"<<i--<<"+"<<" ";
        cap=cap->leg;
    }
    cout<<endl;
}
void Coef(pol *&cap,int a)
{   cout<<"Introduceti "<<a<<" coeficienti"<<endl;
    int x=a,y;
    while(a>0)
    {
        cin>>y;
        a--;
        adaugareSfarsit_coef(cap,y);
    }
}

void Inmultire_scalar(pol *&cap,int a)
{   pol *n=cap;
    if(cap==NULL)
        cout<<"0"<<endl;
    else
    {
        while(cap!=NULL)
        {
            cap->coef=cap->coef*a;
            cap=cap->leg;
        }
    }
    cap=n;
}
void PolX0(pol *cap,int x,int i)
{i--;
int valoare=0;
    if(cap==NULL)
        cout<<"0";
        else
    while(cap!=NULL )
    {
        valoare=valoare+cap->coef*(pow(x,i));
        i--;
        cap=cap->leg;
    }
    cout<<"P("<<x<<")="<<valoare;
    cout<<endl;

}
void Suma(pol *P,pol *Q,pol *&PQ)
{
    int a=P->gr,b=Q->gr;
    pol *n=PQ;
    while(a!=0 || b!=0)
        if(a>b)
    {   adaugareSfarsit_coef(PQ,P->coef);
        a--;
        P=P->leg;


    }
    else
        if(b>a)
    {
        adaugareSfarsit_coef(PQ,Q->coef);
        b--;
        Q=Q->leg;

    }
    else
    {
        adaugareSfarsit_coef(PQ,P->coef+Q->coef);
        b--;a--;Q=Q->leg;P=P->leg;

    }

}
int main()
{   int n,m,x,x0,a,mn;
    pol *P=NULL;
    pol *Q=NULL;
    pol *PQ=NULL;
    cout<<"Introduceti gradul polinomului P: ";cin>>n;
    Coef(P,n+1);
    P->gr=n+1;
    cout<<"Introduceti gradul polinomului Q: ";cin>>m;
    Coef(Q,m+1);
    Q->gr=m+1;
    n++;m++;
    cout<<"P(x)=";
    afisare_pol(P,n);
    cout<<endl;
    cout<<"Q(x)=";
    afisare_pol(Q,m);
    cout<<endl;
    cout<<"1.Inmultirea polinomului P cu un scalar a"<<endl;
    cout<<"2.P(Xo)"<<endl;
    cout<<"3.Suma polinoamelor P si Q"<<endl;
    cin>>x;
    while(x>=1 && x<=3)
    {
        switch(x)
        {
        case 1:
            cout<<"introduceti scalarul: ";
            cin>>a;
            Inmultire_scalar(P,a);
            cout<<"Noul polinom este:";afisare_pol(P,n);
            cout<<endl;
            break;
        case 2:
            cout<<"Introduceti valoarea in care vreti sa evaluati polinomul: ";cin>>x0;
            PolX0(P,x0,n);
            break;
        case 3:
            Suma(P,Q,PQ);
            if(m>n)
                mn=m;
            else
                mn=n;
                cout<<"PQ(x)=";
            afisare_pol(PQ,mn);
            cout<<endl;
        }
        cout<<"1.Inmultirea polinomului P cu un scalar a"<<endl;
    cout<<"2.P(Xo)"<<endl;
    cout<<"3.Suma polinoamelor P si Q"<<endl;
    cin>>x;cout<<endl;
    }
}
