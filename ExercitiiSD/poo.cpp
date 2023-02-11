#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& a, int left, int right) {
          int partitionIndex = left;
          int pivot = a[right];
          for (int i = left;i < right;i++) {
                    if (a[i] < pivot) {
                              swap(a[i], a[partitionIndex]);
                              partitionIndex++;
                    }
          }
          swap(a[right], a[partitionIndex]);

          return partitionIndex;
}
int kthElement(vector<int>& a, int left, int right, int k) {
          int pivot = partition(a, left, right);
          if (left == right) return a[left];
          // cout << left << " " << right << " " << pivot << endl;
          if (pivot == k) return a[pivot];
          if (pivot < k) kthElement(a, pivot + 1, right, k);
          else if (pivot > k) kthElement(a, left, pivot - 1, k);
          else return -1;
}

int main() {
          vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
          int k;
          while (1) {
                    cin >> k;
                    cout << kthElement(a, 0, a.size() - 1, k);
          }
          for (int i = 0;i < a.size();i++) {
                    cout << a[i] << " ";
          }
}