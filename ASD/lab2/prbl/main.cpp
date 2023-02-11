#include <iostream>
using namespace std;
struct NOD{
 int val;
 NOD *next;
}*prim;
void adaugare_final();
void sterg_tot();
void adaugare_inceput();
void add_interior_val();
void afisare_lista();
void caut_dupa_val();
void sterg_dupa_val();
int main()
{
    int n;
    cout<<"Optiuni:\n";
    cout<<"1->Adaugarea unui element la finalul listei\n";
    cout<<"2->Adaugarea unui element la inceputul listei\n";
    cout<<"3->Adaugarea unui element in interiorul listei dupa o anumita valoare\n";
    cout<<"4->Afisare\n";
    cout<<"5->Cauta element dupa valoare\n";
    cout<<"6->Stergere element dupa valoare\n";
    cout<<"7->Stergerea intregii liste\n";
    cout<<"0->Iesire\n\n\n";
    cin>>n;
    while(n){
        switch(n){
            case 1: adaugare_final();break;
            case 2: adaugare_inceput();break;
            case 3: add_interior_val();break;
            case 4: afisare_lista();break;
            case 5: caut_dupa_val();break;
            case 6: sterg_dupa_val();break;
            case 7: sterg_tot();break;
            default: cout<<"Optiunea incorecta\n";
        }
        cin>>n;
    }

    return 0;
}



void adaugare_final(){
    cout<<"\nIntroduceti valoarea: ";
    int valoare;
    cin>>valoare;
    NOD*p= new NOD;
    p->val=valoare;
    p->next=NULL;
    if(prim==NULL){
        prim=p;
        return;
    }
    NOD *act;
    act=prim;
    while(act->next!=NULL){
        act=act->next;
    }
    act->next=p;
}

void sterg_tot(){
    NOD *prec,*act=prim;
    while(act!=NULL){
        prec=act;
        act=act->next;
        delete prec;

    }
    prim=NULL;
}

void adaugare_inceput(){
    cout<<"Introduceti valoarea: ";
    int valoare;
    cin>>valoare;
    NOD *p=new NOD;
    p->val=valoare;
    p->next=prim;
    prim=p;
}
void add_interior_val(){
    cout<<"\nIntroduceti numarul de adaugat si valoarea dupa care adaugati:\n";
    int ad,val;
    cin>>ad>>val;
    NOD *act=prim;
    int poz=1;
    while(act!=NULL){
        if(act->val==val){
            break;
        }
        poz++;
        act=act->next;
    }
    if(act==NULL)
        cout<<"Valoare nu exista.\n";
    else{
        NOD *q= new NOD;
        q->val=ad;
        q->next=act->next;
        act->next=q;
    }

}
void afisare_lista(){
    NOD *r;
    r=prim;
    if(prim==NULL){
        cout<<"Lista este goala.\n";
        return;
    }
    cout<<"Elementele listei sunt:\n";
    while(r!=NULL){
        cout<<r->val<<' ';
        r=r->next;
    }
    cout<<'\n';
}
void caut_dupa_val(){
    cout<<"Introduceti valoarea cautata: ";
    int valoare;
    cin>>valoare;
    NOD *act=prim;
    int poz=1;
    while(act!=NULL){
        if(act->val==valoare){
            cout<<"Valoarea cautata se afla pe pozitia "<<poz<<'\n';
            return;
        }
        poz++;
        act=act->next;
    }
    cout<<"Valoarea cautata nu se afla in lista!\n";
}
void sterg_dupa_val(){
    cout<<"Introduceti vloarea pe care doriti sa o stergeti:";
    int valoare;
    cin>>valoare;
    NOD *act=prim,*prec;
    if(prim==NULL || (prim->next==NULL && prim->val!=valoare)){
        cout<<"Valoare inexistenta in lista!\n";
        return;
    }
    if(prim->val==valoare){
        prim=prim->next;
        delete act;
        cout<<"Elementul a fost sters\n";
        return;
    }
    while(act!=NULL){
        if(act->val==valoare){
            prec->next=act->next;
            delete act;
            cout<<"Elementul a fost sters\n";
            return;
        }
        prec=act;
        act=act->next;
    }
    cout<<"Valoare inexistenta in lista!\n";
}


