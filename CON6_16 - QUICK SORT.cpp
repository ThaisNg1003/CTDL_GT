#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int a[], int l, int r) {
    if (l >= r) return;
    int pivot = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    quickSort(a, l, j);
    quickSort(a, i, r);
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[1000000];
        for (int i = 0; i < n; i++) cin >> a[i];
        quickSort(a, 0, n - 1);
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
