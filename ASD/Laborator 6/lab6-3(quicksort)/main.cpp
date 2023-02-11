#include <iostream>
#include <stdlib.h>

using namespace std;

void quicksort(int st, int dr, int v[])
{
    int i=st, j=dr;
    int pivot=v[st+rand()%(dr-st+1)];
    while(i<=j)
    {
        while(v[i]<pivot) i++;
        while(v[j]>pivot) j--;
        if(i<=j)
        {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
    if(st<j) quicksort(st,j,v);
    if(i<dr) quicksort(i,dr,v);
}
int main()
{
    int i, n, v[100];
    cout<<"n=";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>v[i];
    }
    quicksort(0,n-1,v);
    for(i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
