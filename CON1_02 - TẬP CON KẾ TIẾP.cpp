#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++) cin >> a[i];
        int i = k - 1;
        while (i >= 0 && a[i] == n - k + i + 1) i--;
        if (i < 0) {
            for (int j = 1; j <= k; j++) cout << j << " ";
        } else {
            a[i]++;
            for (int j = i + 1; j < k; j++) a[j] = a[j - 1] + 1;
            for (int j = 0; j < k; j++) cout << a[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
