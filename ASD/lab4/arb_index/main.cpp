#include <iostream>
using namespace std;
struct nod{int nro, leftsize;
               nod*st,*dr;};
nod *r;
int k=1;
void inserare(nod *&c,int k)
{if(c)
   if(c->nro==k)
        cout<<"Numar deja inserat "<<'\n';
   else
     if(c->nro<k)
             {inserare(c->dr,k);

             }
     else
             {inserare(c->st,k);
            c->leftsize+=1;
             }
 else
     {c=new nod;
      c->nro=k;
      c->st=c->dr=0;
      c->leftsize=0;}
}

int cautare(nod *c,int k)
{if(c)
    if(c->leftsize==k)
            return c->nro;
    else
            if(c->leftsize<k)
               cautare(c->dr,k-c->leftsize-1);
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
     cout<<"\nDati indexul cautat: ";
     int nr;
     cin>>nr;
     if (cautare(r,nr))
     cout<<"Gasit: "<<cautare(r,nr);
     else
        cout<<"Index inexistent";
    return 0;
}
