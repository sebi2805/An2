#include <iostream>
using namespace std;
int h[1000],monezi,s;
int main()
{   int n;
    cout<<"Introduceti numarul haiducilor:";
    cin>>n;
    cout<<"Introduceti numarul monezilor:";
    cin>>monezi;
    int i;
    if (n%2==0)
    {for (i=2;i<n;i=i+2)
        h[i]=1,s=s+1;
    h[n]=monezi-s;
    }
    else
    {
        for (i=1;i<n;i=i+2)
            h[i]=1,s=s+1;
        h[n]=monezi-s;
    }
    cout<<"\n";
    for (i=n;i>=1;i--)
        cout<<"H"<<i<<"\t";
    cout<<'\n';
    for (i=n;i>=1;i--)
        cout<<h[i]<<"\t";
    cout<<'\n'<<'\n';
    cout<<"Explicatii:\n";
    cout<<"Cel mai tanar haiduc stie ca prima lui sansa de a primi ceva este de la haiducul 9, care are de convins 4 haiduci.\n";
    cout<<"Avand in vedere ca haiducul 10 (cel mai batran) are de convins tot 4 haiduci, el ii va plati cu un singur galben pe cei cu numar par.\n";
    cout<<"Haiducii se tem unii de altii dar si de faptul ca cei care nu vor primi runda urmatoare nici o moneda, \nisi vor da votul in prima runda chiar si pentru o moneda.\n\n";

    return 0;
}
