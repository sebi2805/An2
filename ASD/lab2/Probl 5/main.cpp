#include <iostream>

using namespace std;
 struct NOD{
 float val ;
 NOD *next;
 }*prim;
int main()
{
    int  n,i;
    cin>>n;
   if(n==0){
        cout<<"Lista vida!";
        return 0;
    }
    else{
        NOD *q= new NOD;
        cin>>q->val;
        q->next=NULL;
        prim=q;
    }

    for(i=2;i<=n;i++){
        NOD *q= new NOD;
        cin>>q->val;
        q->next=NULL;
        NOD *p=prim;
        while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
    NOD *q=prim;
    while(q->next!=NULL){
        NOD *p = new NOD;
        p->val = ( q->val + (q->next)->val )/2.0;
        p->next=q->next;
        q->next=p;
        q=q->next;
        q=q->next;
    }
    q=prim;
    while(q!=NULL){
        cout<<q->val<<' ';
        q=q->next;
    }
    return 0;
}
