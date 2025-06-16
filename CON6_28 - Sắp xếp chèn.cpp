#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b;
        for (int &x : a) cin >> x;

        vector<vector<int>> steps;

        for (int i = 0; i < n; i++) {
            b.push_back(a[i]);
            for (int j = i; j > 0 && b[j] < b[j - 1]; j--) {
                swap(b[j], b[j - 1]);
            }
            steps.push_back(b); // Lưu lại bước hiện tại
        }

        // In ngược lại các bước
        for (int i = n - 1; i >= 0; i--) {
            cout << "Buoc " << i << ": ";
            for (int x : steps[i]) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}
