#include <iostream>
using namespace std;

struct POL{
int grad;
int val;
POL *next;
}*prim;
int put(int valoare, int putere){
    int p=1;
    while(putere--){
        p*=valoare;
    }
    return p;
}
int main()
{
    int n,i,x0;
    cout<<"Introduceti gradul:";
    cin>>n;
    cout<<"Introduceti coeficientul si gradul:\n";
    prim= new POL;
    cin>>prim->val;
    cin>>prim->grad;
    prim->next=NULL;
    for(i=2;i<=n;i++){
        POL *q=new POL;
        cin>>q->val;
        cin>>q->grad;
        q->next=prim;
        prim=q;
    }
    cout<<"\nIntroduceti X0:";
    cin>>x0;
    int val=0;
    POL *q=prim;
    while(q!=NULL){
        val+=(q->val)*put(x0,q->grad);
        q=q->next;
    }
    cout<<val;
    return 0;
}
