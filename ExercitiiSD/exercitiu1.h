
#include <iostream>
#include <vector>
using namespace std;
int minCirc(vector<int>& a)
{
    int st = 0, dr = a.size() - 1, mijloc;
    while (dr - st > 0)
    {
        mijloc = (st + dr + 1) / 2;
        if (dr - st == 1)
        {
            return dr;
        }
        cout << st << " " << dr << endl;
        if (a[mijloc] < a[st])
        {
            dr = mijloc;
        }
        else
            st = mijloc;
    }
    return mijloc;
}
int firstCirc(vector<int>& a, int e) {
    int st = 0, dr = a.size() - 1, mijloc;
    while (dr - st > 0)
    {
        cout << st << " " << dr << endl;
        mijloc = (st + dr + 1) / 2;
        if (dr - st == 1)
        {
            if (a[dr] == e) return dr;
            if (a[st] == e) return st;
        }

        if (a[mijloc] == e) return mijloc;
        if (a[st] > a[dr]) {
            if (e < a[mijloc]) { dr = mijloc; }
            else if (e > a[mijloc]) { st = mijloc; }
        }
        else {
            if (e > a[mijloc]) {
                st = mijloc;
            }
            else if (e < a[mijloc]) { dr = mijloc; }
        }
    }
    return mijloc;


}