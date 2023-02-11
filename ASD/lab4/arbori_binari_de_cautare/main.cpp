#include<iostream>
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
            return 1;
    else
            if(c->nro<k)
               cautare(c->dr,k);
            else
               cautare(c->st,k);
 else
    return 0;
}
void svd(nod *c)
   {if(c)
            {svd(c->st);
             cout<<c->nro<<" ";
             svd(c->dr);
            }
   }


void vsd(nod *c)
   {if(c)
            {cout<<c->nro<<" ";
             vsd(c->st);
             vsd(c->dr);
            }
   }

void sdv(nod *c)
   {if(c)
            {sdv(c->st);
             sdv(c->dr);
             cout<<c->nro<<" ";
            }
   }
/**
nod* citire_h()
{int nr;
 nod*c;
 cout<<"nr de ordine ";
 cin>>nr;
 if(nr)
       {c=new nod;
            c->nro=nr;
            c->st=citire_h();
            c->dr=citire_h();
            return c;
            }
 else
     return 0;
}
*/

void cmd(nod* &c,nod* &f)
{nod *aux;
 if(f->dr)
    cmd(c,f->dr);
 else
     {c->nro=f->nro;
      aux=f;
      f=f->st;
      delete aux;
      }
}

void sterg(nod *&c,int k)
{nod *aux,*f;
 if(c)
   if(c->nro==k)
       if(c->st==0&&c->dr==0)  ///daca e nod terminal
               {delete c;
                c=0;
                }
            else
               if(c->st==0)      ///are numai subordonat drept
                 {aux=c->dr;
                  delete c;
                  c=aux;}
                else
                   if(c->dr==0)    ///are numai subordonat drept
                          {aux=c->st;
                           delete c;
                           c=aux;}
                   else
                           cmd(c,c->st);  ///are ambii subordonati

   else
     if(c->nro<k)
            sterg(c->dr,k);
     else
            sterg(c->st,k);

 else
      cout<<"Valoarea nu poate fi stearsa. Nu se gaseste in arbore.";
}

int findmax(nod *p)
{
    while(p->dr)
    {
        p=p->dr;
    }
    return p->nro;
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

     cout<<'\n'<<"Arborele contine urmatoarele noduri: "<<'\n';
     svd(r);
     cout<<'\n'<<"Dati valoarea pe care doriti sa o stergeti din arbore: ";
     cin>>a;
     sterg(r,a);
     cout<<'\n'<<"Arborele dupa stergere: "<<'\n';
     svd(r);
     cout<<'\n'<<"Dati valoarea cautata: ";
     cin>>a;
     if(cautare(r,a))
        cout<<"Gasit!";
     else
        cout<<"Nu s-a gasit!";

     ///r=citire_h();
    cout<<'\n'<<"Parcurgere svd - in inordine "<<'\n';
    svd(r);
    cout<<'\n'<<"Parcurgere vsd - in preordine "<<'\n';
    vsd(r);
    cout<<'\n'<<"Parcurgere sdv - in postordine "<<'\n';
    sdv(r);
    cout<<'\n'<<"Maximul este:"<<findmax(r);
    return 0;
}
