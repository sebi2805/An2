#include<iostream>
using namespace std;

struct nod
{int info; nod *back;};
nod *varf;

void push(int x, nod* &v)
{
    nod *c;
    if(!v)
        {v=new nod;
         v->info=x;
         v->back=0;
         }
     else
         {c=new nod;
          c->back=v;
          c->info=x;
          v=c;
          }
}

void afisare(nod *v)
{nod *c;
cout<<"\nStiva:";
 c=v;
 while(c)
    {cout<<c->info<<" ";
     c=c->back;}
}

void pop(nod* &v)
{nod* c;
if(!v)
    cout<<"\nStiva este vida. Nu ai ce elimina!";
 else
    {c=v;
     v=v->back;
     delete c;}
cout<<"Varful a fost eliminat.";
afisare(v);
}
void peek(nod* &v)
{
if(!v)
    cout<<"\nStiva este vida. Nu ai ce afisa!";
 else
    {cout<<v->info;}
}
void empt(nod* &v)
{
if(!v)
    cout<<"\nStiva este vida!";
 else
    {cout<<"\nStiva NU este vida!";}
}
int cauta(int x,nod *v)
{nod *c;
 c=v;
 int dist=-1,ok=0;
 while(c)
    {if (x==c->info)
        {dist+=1;ok=1;
        return dist;}
     else
     {dist+=1;
     c=c->back;}
    }
if (ok==1)
return dist;
else
    return -1;
}
int main()
{int n,a;
 int meniu=10;
 cout<<"Meniu:\n";
 cout<<"1. Adaugati un element in stiva.\n";
 cout<<"2. Scoateti un element din stiva (varful).\n";
 cout<<"3. Peek. (Intoarce elementul din varf fara sa il stearga).\n";
 cout<<"4. Verifica daca stiva este sau nu vida.\n";
 cout<<"5. Cauta un element.\n";
 cout<<"6. Afiseaza stiva.\n";
 cout<<"0 - OPRIRE";
 cout<<"\n";
 do {
    cout<<"\nAlegeti optiunea din meniu:";cin>>meniu;
    if (meniu==1)
       {cout<<"Valoarea de adaugat in stiva: ";
        cin>>a;
        push(a,varf);
        }
    else
        if (meniu==2)
            pop(varf);
        else
            if (meniu==3)
                peek(varf);
            else
                if (meniu==4)
                    empt(varf);
                else
                    if (meniu==5)
                    {   int x;
                        cout<<"\nDati elementul cautat:";
                        cin>>x;
                        cout<<cauta(x,varf);
                    }
                    else
                        if (meniu==6)
                            afisare(varf);
 }while (meniu!=0);

return 0;

 }
