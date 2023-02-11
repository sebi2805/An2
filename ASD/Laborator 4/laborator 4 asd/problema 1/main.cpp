#include <iostream>
#include <stdlib.h>
#include <math.h>


using namespace std;
struct arbore
{
    int info;
    arbore *left;
    arbore *right;
};
arbore *Root;

void Insert (int info, arbore** node)
{
    if(*node==NULL)
    {
        *node= new arbore;
        (*node)->info=info;
        (*node)->left=NULL;
        (*node)->right=NULL;

    }
    else if((*node)->info > info)
    {
        Insert(info, &(*node)->left);
    }
    else if((*node)->info < info)
    {
        Insert(info, &(*node)->right);
    }

}

int cautare(arbore *node,int k)
{
if(node)
    if(node->info==k)
            cout<<"S-a gasit"<<endl;
    else
            if(node->info<k)
               cautare(node->right,k);
            else
               cautare(node->left,k);
 else
    cout<<"Nu s-a gasit ";
}
int findMax(arbore *node)
{
    while(node->right!=NULL)
    {
        node=node->right;
    }
    cout<<node->info;
}
void cmd(arbore* &node,arbore* &f)
{arbore *aux;
 if(f->right)
    cmd(node,f->right);
 else
     {node->info=f->info;
      aux=f;
      f=f->left;
      delete aux;
      }
}
void sterg(arbore *&node,int k)
{arbore *aux,*f;
 if(node)
   if(node->info==k)
       if(node->left==0&&node->right==0)  //daca e nod terminal
               {delete node;
                node=0;
                }
            else
               if(node->left==0)      //are numai subordonat drept
                 {aux=node->right;
                  delete node;
                  node=aux;}
                else
                   if(node->right==0)    //are numai subordonat drept
                          {aux=node->left;
                           delete node;
                           node=aux;}
                   else
                           cmd(node,node->left);  //are ambii subordonati

   else
     if(node->info<k)
            sterg(node->right,k);
     else
            sterg(node->left,k);

 else
      cout<<"valoarea de sters nu se gaseste in arbore ";
}

void srd(arbore *node)
{
    if(node)
    {
        srd(node->left);
        cout<<node->info<<" ";
        srd(node->right);
    }
}
void rsd(arbore *node)
{
    if(node)
    {
        cout<<node->info<<" ";
        rsd(node->left);
        rsd(node->right);
    }
}

void sdr(arbore *node)
{
    if(node)
    {
        sdr(node->left);
        sdr(node->right);
        cout<<node->info<<" ";
    }
}



int main()
{
    int n,i,x;

    cin>>n;
    for(i = 1; i <= n; i++)

    {
        cin>>x;

        Insert(x, &Root);
    }

cin>>x;
cautare(Root, x);

  cout<<"parcurgere SRD: ";  srd(Root);
    cout<<endl;
    cout<<"Parcurgere RSD: "; rsd(Root);
    cout<<endl;
    cout<<"Parcurgere SDR: "; sdr(Root);
    cout<<endl;
   cout<<"maximul este "; findMax(Root);
   cout<<endl;
cin>>x;
sterg(Root, x);
srd(Root);




    return 0;
}
