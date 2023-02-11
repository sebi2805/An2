#include <iostream>
using namespace std;

struct POL1{
    int grad;
    int val;
    POL1 *next;
}*prim1;

struct POL2{
int grad;
int val;
POL2 *next;
}*prim2;
struct POLS{
    int grad;
    int val;
    POLS *next;
}*prims;
using namespace std;
void afisare(POLS *q){
    if(q!=NULL){
        afisare(q->next);
        cout<<q->val<<"x^"<<q->grad<<" ";
    }
}
void create(int grad, int valoare){
    POLS *q = new POLS;
    q->grad=grad;
    q->val=valoare;
    q->next=prims;
    prims=q;
}
void add(int grad, int valoare){
    POLS *q=prims;
    while(q!=NULL&&q->grad!=grad)
        q=q->next;
    if(q==NULL)
        create(grad,valoare);
    else{
        q->val+=valoare;
    }
}
void add1(){
    POL1 *act= new POL1;
    cin>>act->val>>act->grad;
    POL1 *q=prim1;
    POL1 *prec=q;
    while(q!=NULL&&q->grad<act->grad){
        prec=q;
        q=q->next;
    }
    if(q==prim1){
        act->next=prim1;
        prim1=act;
    }else{
        act->next=prec->next;
        prec->next=act;
    }
}

void add2(){
    POL2 *act= new POL2;
    cin>>act->val>>act->grad;
    POL2 *q=prim2;
    POL2 *prec=q;
    while(q!=NULL&&q->grad<act->grad){
        prec=q;
        q=q->next;
    }
    if(q==prim2){
        act->next=prim2;
        prim2=act;
    }else{
        act->next=prec->next;
        prec->next=act;
    }
}
int main()
{
    int n,i,x0;
    cout<<"Introduceti gradul pentru primul polinom:";
    cin>>n;
    cout<<"Introduceti coeficientul si gradul:\n";
    prim1= new POL1;
    cin>>prim1->val;
    cin>>prim1->grad;
    prim1->next=NULL;
    for(i=2;i<=n;i++){
        add1();
    }

    cout<<"Introduceti gradul pentru al doilea polinom:";
    cin>>n;
    cout<<"Introduceti coeficientul si gradul:\n";
    prim2= new POL2;
    cin>>prim2->val;
    cin>>prim2->grad;
    prim2->next=NULL;
    for(i=2;i<=n;i++){
        add2();
    }
    POL1 *p=prim1;
    POL2 *q=prim2;

    for(;p!=NULL;p=p->next){
        create(p->grad,p->val);
    }
    for(;q!=NULL;q=q->next)
        add(q->grad,q->val);
    afisare(prims);
    return 0;
}
