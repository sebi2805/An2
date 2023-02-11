#include <iostream>
using namespace std;
struct coada{
    int val;
    coada *next;
}*prim,*ultim;
bool empty_(){
    if(prim==ultim&&prim==NULL)
        return 1;
    return 0;
}
void push(int val){
    if(empty_()){
        prim = new coada;
        prim->next=NULL;
        ultim = new coada;
        ultim->next=NULL;
        prim->val=val;
        ultim=prim;
        return;
    }
    coada *q= new coada;
    q->val=val;
    q->next=NULL;
    ultim->next=q;
    ultim=q;

}
int pop(){
    if(empty_())
        return -1;
    int val=prim->val;
    coada *q=prim;
    if(prim==ultim){
        prim=ultim=NULL;
        delete q;
        return val;
    }
    prim=prim->next;
    delete q;
    return val;
}
int peek(){
    if(empty_())
        return -1;
    return prim->val;
}
int search_(int val){
    if(empty_())
        return -1;
    coada *q= prim;
    int dist=0;
    while(q->next!=NULL&&q->val!=val){
        q=q->next;
        dist++;
    }
    if(q==NULL)
        return -1;
    return dist;
}
void afiseaza(){
    if(empty_()){
        cout<<"Coada vida!";
        return;
    }
    coada *q = prim;
    while(q!=NULL){
        cout<<q->val<<" ";
        q=q->next;
    }
}
int main()
{
    int n,a;
 int meniu=10;
 cout<<"Meniu:\n";
 cout<<"1. Adaugati un element in coada.\n";
 cout<<"2. Scoateti un element din coada.\n";
 cout<<"3. Peek. (Intoarce elementul din varf fara sa il stearga).\n";
 cout<<"4. Verifica daca coada este sau nu vida.\n";
 cout<<"5. Cauta un element.\n";
 cout<<"6. Afiseaza coada.\n";
 cout<<"0 - OPRIRE";
 cout<<"\n";
 do {
    cout<<"\nAlegeti optiunea din meniu:";cin>>meniu;
    if (meniu==1)
       {cout<<"Valoarea de adaugat in coada: ";
        cin>>a;
        push(a);
        }
    else
        if (meniu==2)
            pop();
        else
            if (meniu==3)
                cout<<peek();
            else
                if (meniu==4)
                    cout<<empty_();
                else
                    if (meniu==5)
                    {   int x;
                        cout<<"\nDati elementul cautat:";
                        cin>>x;
                        cout<<search_(x);
                    }
                    else
                        if (meniu==6)
                            afiseaza();
 }while (meniu!=0);

return 0;
    return 0;
}
