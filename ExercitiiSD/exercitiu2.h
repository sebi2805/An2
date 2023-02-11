
#include <iostream>
#include <vector>
using namespace std;
int sort(vector<int>& array, int l, int h, int k)
{
    int mid = l + (h - l) / 2; //Aleg pivotul
    int i = max(l, mid - k), j = i, end = min(mid + k, h); // De unde pana unde
    swap(array[mid], array[end]); //schimb ultimul cu mijloc ca sa scap de complicatii, daca i depaseste mijlocul
    while (j < end) {
        if (array[j] < array[end]) {
            swap(array[i++], array[j]);
        }
        j = j + 1;
    }
    swap(array[end], array[i]);
    return i;
}
void ksorter(vector<int>& array, int l, int h, int k)
{
    if (l < h) {
        int q = sort(array, l, h, k);
        ksorter(array, l, q - 1, k);
        ksorter(array, q + 1, h, k);
    }
}