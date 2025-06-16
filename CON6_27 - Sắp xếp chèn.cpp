#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; 
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            tmp.push_back(a[i]);
            // Sắp xếp phần tử từ đầu đến vị trí i
            for (int j = i; j > 0 && tmp[j] < tmp[j - 1]; j--) {
                swap(tmp[j], tmp[j - 1]);
            }
            // In bước
            cout << "Buoc " << i << ": ";
            for (int k = 0; k <= i; k++) {
                cout << tmp[k] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
