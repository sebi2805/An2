#include <iostream>
using namespace std;

struct nod{int nro;
               nod*st,*dr;};
nod *r;
void inserare(nod *&c,int k)
{if(c)
   if(c->nro==k)
        cout<<"Numar deja inserat "<<'\n';
   else
     if(c->nro<k)
             inserare(c->dr,k);
     else
             inserare(c->st,k);

 else
     {c=new nod;
      c->nro=k;
      c->st=c->dr=0;}
}
int cautare(nod *c,int k)
{if(c)
    if(c->nro==k)
            return k;
    else
            if(c->nro<k)
               cautare(c->dr,k);
            else
               cautare(c->st,k);
 else
    return 0;
}
int main()
{
    int i,n,a;
    cout<<"Dati numarul de noduri: ";
    cin>>n;
    for(i=1;i<=n;i++)
    {cout<<"Valoare de inserat: ";
     cin>>a;
     inserare(r,a);
    }
    int k1,k2;
    cout<<"Dati k1: ";
    cin>>k1;
    cout<<"Dati k2: ";
    cin>>k2;
    for (i=k1;i<=k2;i++)
        if (cautare(r,i))
        cout<<cautare(r,i)<<" ";
    return 0;
}
