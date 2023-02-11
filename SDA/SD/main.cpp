#include <iostream>
#include <vector>
using namespace std;

int minCirc(int a[], int n)
{
    int stanga = 0, dreapta = n, aux = 0, mijloc;

    while (dreapta - stanga > 0)
    {
        mijloc = (dreapta + stanga + 1) / 2;
        // cout<<"mijloc "<<mijloc << endl;
        // if(a[mijloc]<a[stanga]&&a[mijloc]<a[dreapta]) return mijloc;
        if (a[mijloc] < a[dreapta])
        {
            dreapta = mijloc;
        }
        else
        {
            stanga = mijloc;
        }
    }
    return mijloc;
};

int firstCirc(int a[], int n, int e)
{
    int stanga = 0, dreapta = n, mijloc;
    while (dreapta - stanga > 1)
    {
        mijloc = (dreapta + stanga + 1) / 2;

        if (e < a[mijloc] && e > a[stanga])
        {
            dreapta = mijloc;
        }
        else if (e < a[mijloc] && e < a[dreapta])
        {
            dreapta = mijloc;
        }
        else if (e > a[mijloc] && e < a[dreapta])
        {
            stanga = mijloc;
        }
        else if (e == a[mijloc])
            return mijloc;
    }

    return -1;
}

int main()
{
    // int a[]={4,5,6,7,8,9,10,11,12,13,1,2,3};
    int a[] = {11, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 10};

    cout << minCirc(a, 11) << ":" << a[minCirc(a, 11)];
    //  cout<<a[firstCirc(a, 11, 2)];
}
