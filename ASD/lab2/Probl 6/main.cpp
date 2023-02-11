#include <iostream>
#include <string.h>
using namespace std;
struct el_1{
unsigned short int val;
el_1 *next;
}*prim1;
struct el_2{
unsigned short int val;
el_2 *next;
}*prim2;
struct sum{
unsigned short int val;
sum *next;
}*prims;
char s[101];
int convert(char c){
    return c-'0';
}
void afis(sum *q){
    while(q!=NULL){
        cout<<q->val;
        q=q->next;
    }
}
int main()
{
    int i;
    cin.getline(s,100);
    el_1 *aa= new el_1;
    aa->val=convert(s[0]);
    aa->next=NULL;
    prim1 = aa;
    for(i=1;s[i]>='0' && s[i]<='9';i++){
        el_1 *q= new el_1;
        q->val=convert(s[i]);
        q->next=prim1;
        prim1=q;
    }
    cin.getline(s,100);
    el_2 *bb= new el_2;
    bb->val=convert(s[0]);
    bb->next=NULL;
    prim2=bb;
    for(i=1;s[i]>='0' && s[i]<='9';i++){
        el_2 *q= new el_2;
        q->val=convert(s[i]);
        q->next=prim2;
        prim2=q;
    }
    el_1 *p = prim1;
    el_2 *q = prim2;
    sum *ss = new sum;
    ss->val = (p->val + q->val) % 10;
    ss->next = NULL;
    prims = ss;
    unsigned short int t = (p->val + q->val) /10;
    p=p->next;
    q=q->next;
    while(p!=NULL && q!=NULL){
        sum *s = new sum;
        s->val = (p->val + q->val + t) % 10;
        t = (p->val + q->val + t) / 10;
        s->next = prims;
        prims = s;

        p = p->next;
        q = q->next;
    }
    while(p!=NULL){
        sum *s = new sum;
        s->val = (p->val +t) % 10;
        t = (p->val +t) / 10;
        s->next = prims;
        prims = s;
        p = p->next;
    }
    while (q!=NULL){
        sum *s = new sum;
        s->val = (q->val +t) % 10;
        t = (q->val +t) / 10;
        q = q->next;
        s->next = prims;
        prims = s;

    }
    if(t!=0){
        sum *s = new sum;
        s->val = t;
        s->next = prims;
        prims = s;
    }
    afis(prims);
    return 0;
}
