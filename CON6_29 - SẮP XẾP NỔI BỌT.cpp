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

        int buoc = 1;
        for (int i = 0; i < n - 1; i++) {
            bool da_hoan_doi = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    da_hoan_doi = true;
                }
            }
            if (da_hoan_doi) {
                cout << "Buoc " << buoc << ": ";
                for (int k = 0; k < n; k++) {
                    cout << a[k] << " ";
                }
                cout << "\n";
                buoc++;
            } else {
                break; // không còn đổi nữa => đã sắp xếp xong
            }
        }
    }
    return 0;
}
