#include <iostream>
using namespace std;

struct POL{
int grad;
int val;
POL *next;
}*prim;
void add(){
    POL *act= new POL;
    cin>>act->val>>act->grad;
    POL *q=prim;
    POL *prec=q;
    while(q!=NULL&&q->grad<act->grad){
        prec=q;
        q=q->next;
    }
    if(q==prim){
        act->next=prim;
        prim=act;
    }else{
        act->next=prec->next;
        prec->next=act;
    }

}
int main()
{
    int n,i,scalar;
    cout<<"Introduceti numarul de grade:";
    cin>>n;
    cout<<"Introduceti coeficientul si gradul:\n";
    prim= new POL;
    cin>>prim->val;
    cin>>prim->grad;
    prim->next=NULL;
    for(i=2;i<=n;i++)
        add();
    cout<<"\nIntroduceti scalarul:";
    cin>>scalar;
    POL *q=prim;
    while(q!=NULL){
        q->val=q->val*scalar;
        q=q->next;
    }
    q=prim;
    while(q->next!=NULL){
        cout<<q->val<<"x^"<<q->grad<<"+";
        q=q->next;
    }
    cout<<q->val<<"x^"<<q->grad<<"=0";
    return 0;
}
