#include <iostream>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int maxA = INT_MIN, minB = INT_MAX, x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x > maxA) maxA = x;
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            if (x < minB) minB = x;
        }
        cout << maxA * minB << endl;
    }
    return 0;
}
