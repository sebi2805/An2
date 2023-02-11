#include <iostream>
using namespace std;

struct AVL
{
    int cheie;
    struct AVL *stanga;
    struct AVL *dreapta;
    int inaltime;
};

/* Inaltimea unui subarbore */
int inaltime(struct AVL *x)
{
    if (x == NULL)
        return 0;
    return x->inaltime;
}

/* Maximul dintre doua numere*/
int maxim(int a, int b)
{
    if (a<b)
        return b;
    else
        return a;
}

/* Creaza un nod nou */
struct AVL* nodNou(int cheie)
{
    struct AVL* nod = new AVL;
    nod ->cheie   = cheie;
    nod ->stanga   = NULL;
    nod ->dreapta  = NULL;
    nod ->inaltime = 1;
    return(nod);
}

/* Rotatie dreapta */
struct AVL *rotatieDreapta(struct AVL *y)
{
    struct AVL *x = y->stanga;
    struct AVL *T2 = x->dreapta;
    /// Rotatia
    x->dreapta = y;
    y->stanga = T2;
    /// Reactualizeaza inaltimea subarborelui
    y->inaltime = maxim(inaltime(y->stanga), inaltime(y->dreapta))+1;
    x->inaltime = maxim(inaltime(x->stanga), inaltime(x->dreapta))+1;
    /// Intoarce noua radacina
    return x;
}

/* Rotatie stanga */
struct AVL *rotatieStanga(struct AVL *x)
{
    struct AVL *y = x->dreapta;
    struct AVL *T2 = y->stanga;
    /// Rotatia
    y->stanga = x;
    x->dreapta = T2;
    ///  Actualizeaza inaltimea arborelui
    x->inaltime = maxim(inaltime(x->stanga), inaltime(x->dreapta))+1;
    y->inaltime = maxim(inaltime(y->stanga), inaltime(y->dreapta))+1;
    /// Intoarce noua radacina
    return y;
}

/* Factorul de echilibrare */
int echilibreaza(struct AVL *N)
{
    if (N == NULL)
        return 0;
    return inaltime(N->stanga) - inaltime(N->dreapta);
}

/*Adauga chei in arbore */
struct AVL* adauga(struct AVL* nod, int cheie)
{
    //Se adauga chei
    if (nod == NULL)
        return(nodNou(cheie));

    if (cheie < nod->cheie)
        nod->stanga  = adauga(nod->stanga, cheie);
    else if (cheie > nod->cheie)
        nod->dreapta = adauga(nod->dreapta, cheie);
    else
        return nod;

    // Se actualizeaza inaltime stramosilor
    nod->inaltime = 1 + maxim(inaltime(nod->stanga), inaltime(nod->dreapta));

    //Se verifica daca nodul este echilibrat
    int balance = echilibreaza(nod);

    //Daca nodul este dezechilibrat, avem urmatoarele 4 cazuri:

    // 1. Rotatie Stanga-Stanga
    if (balance > 1 && cheie < nod->stanga->cheie)
        return rotatieDreapta(nod);

    // 2. Rotatie Dreapta-Dreapta
    if (balance < -1 && cheie > nod->dreapta->cheie)
        return rotatieStanga(nod);

    // 3. Rotatie Stanga-Dreapta
    if (balance > 1 && cheie > nod->stanga->cheie)
    {
        nod->stanga =  rotatieStanga(nod->stanga);
        return rotatieDreapta(nod);
    }

    // 4.Rotatie Dreapta-Stanga
    if (balance < -1 && cheie < nod->dreapta->cheie)
    {
        nod->dreapta = rotatieDreapta(nod->dreapta);
        return rotatieStanga(nod);
    }

    return nod;
}

/* Cauta un element in arbore */

void cauta(AVL *p,int x)
{
    if(!p)
        cout<<"\nElementul "<<x<<" nu se afla in arbore.\n\n";
    else if(x<p->cheie)
        cauta(p->stanga,x);
    else if(x>p->cheie)
        cauta(p->dreapta,x);
    else
    cout<<"\nElementul "<<x<<" a fost gasit.\n\n";
}

/* Gaseste valoarea minima din arbore */
struct AVL* nodMinim(struct AVL* nod)
{
    struct AVL* curent = nod;

    while (curent->stanga != NULL)
        curent = curent->stanga;

    return curent;
}

/* Gaseste valoarea maxima din arbore*/
int cautaMax(struct AVL* root)
{
    if (root == NULL)
      return INT_MIN;

    int x = root->cheie;
    int lx = cautaMax(root->stanga);
    int rx = cautaMax(root->dreapta);
    if (lx > x)
      x = lx;
    if (rx > x)
      x = rx;
    return x;
}

/*Sterge un nod dintr-un subarbore dandu-se o cheie */
struct AVL* sterge(struct AVL* root, int cheie)
{
    if (root == NULL)
        return root;

    //Avem cazurile:
    // 1. Cheia de sters este mai mica decat cheia radacinii
    if ( cheie < root->cheie )
        root->stanga = sterge(root->stanga, cheie);

    // 2. Cheia de sters este mai mare decat cheia radacinii
    else if( cheie > root->cheie )
        root->dreapta = sterge(root->dreapta, cheie);

    // 3. Cheia de sters este cheia radacinii
    else
    {
        if( (root->stanga == NULL) || (root->dreapta == NULL) )
        {
            struct AVL *temp = root->stanga ? root->stanga : root->dreapta;


            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;

            delete temp;
        }
        else
        {

            struct AVL* temp = nodMinim(root->dreapta);


            root->cheie = temp->cheie;


            root->dreapta = sterge(root->dreapta, temp->cheie);
        }
    }

    if (root == NULL)
      return root;

    // Actuealizeaza inaltimea nodului curent
    root->inaltime = 1 + maxim(inaltime(root->stanga), inaltime(root->dreapta));

    // Verificam daca nodul este echlibrat
    int balance = echilibreaza(root);

    // Daca nodul este dezechilibrat avem cazurile:

    // 1. Cazul Stanga-Stanga
    if (balance > 1 && echilibreaza(root->stanga) >= 0)
        return rotatieDreapta(root);

    // 2. Cazul Stanga-Dreapta
    if (balance > 1 && echilibreaza(root->stanga) < 0)
    {
        root->stanga =  rotatieStanga(root->stanga);
        return rotatieDreapta(root);
    }

    // 3.Cazul Dreapta - Dreapta
    if (balance < -1 && echilibreaza(root->dreapta) <= 0)
        return rotatieStanga(root);

    // 4. Cazul Dreapta - Stanga
    if (balance < -1 && echilibreaza(root->dreapta) > 0)
    {
        root->dreapta = rotatieDreapta(root->dreapta);
        return rotatieStanga(root);
    }

    return root;
}

/* Afiseaza in ordine crescatoare cheile arborelui */

void inOrdine(struct AVL *root)
{
    if(root != NULL)
    {
        inOrdine(root->stanga);
        cout<<root -> cheie<<" ";
        inOrdine(root->dreapta);
    }
}


int main()
{
  int n;
  int k,x;
  struct AVL *root = NULL;
  cout<<"AVL meniu: \n\n1.Adaugare.\n2.Cautare.\n3.Element maxim.\n4.Sterge.\n5.Afiseaza.\n0.Iesire.\n\n";
  do {
        cout<<"Alegeti din meniu:";
        cin>>k;
        if (k==1)
        {
            cout<<"Introduceti elementul:";
            cin>>x;
            root=adauga(root,x);
        }
        else
            if (k==2)
            {   cout<<"Dati elementul cautat:";
                cin>>n;
                cauta(root,n);
            }
            else
                if (k==3)
                {
                    cout<<"Maximul este: "<<cautaMax(root)<<"\n";
                }
                else
                    if (k==4)
                    {
                        cout<<"Dati elementul pe care doriti sa il stergeti:";
                        cin>>x;
                        root=sterge(root,x);
                    }
                    else
                        if (k==5)
                    {
                        inOrdine(root);
                    }
                    cout<<"\n";
  }while(k!=0);

  return 0;
}
