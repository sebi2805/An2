#include <iostream>

using namespace std;
struct stiva{
    int val;
    stiva *next;
}*prim;
int empty_(){
    if(prim==NULL)
        return 1;
    return 0;
}
void push(int val){
    if(prim==NULL){
        prim= new stiva;
        prim->val=val;
        prim->next=NULL;
        return;
    }
    stiva *q= new stiva;
    q->val=val;
    q->next=prim;
    prim=q;
}
void pop(){
    stiva *q=prim;
    prim=prim->next;
    delete q;
}
int peek(){
    return prim->val;
}
int main()
{
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(empty_())
            push(x);
        else{
            if(peek()==x)
                pop();
            else
                push(x);
        }
    }
    if(empty_())
        cout<<"Configuratie valida";
    else
        cout<<"Configuratia nu este valida";
    return 0;
}
