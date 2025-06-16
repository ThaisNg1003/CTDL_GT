#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(a[i] - a[j]) < k) count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
