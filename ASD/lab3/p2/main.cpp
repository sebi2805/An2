#include <iostream>
#include <string.h>
using namespace std;
struct stiva{
    char val;
    stiva *next;
}*prim;
char s[1001];
char peek(){
    if(prim==NULL)
        return 0;
    return prim->val;
}
void add(int val){
    if(prim==NULL){
        prim= new stiva;
        prim->next=NULL;
        prim->val=val;
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
int main()
{
    cin.getline(s,100);
    for(int i=0;i<strlen(s);i++){
        if(peek()){
            if(s[i]!=peek())
                pop();
            else add(s[i]);
        }
        else
            add(s[i]);
    }
    if(prim==NULL)
        cout<<"Aparitii egale pentru caracterele 'a' si 'b'.";
    else
        cout<<"Aparitii diferite pentru caracterele 'a' si 'b'.";
    return 0;
}
