#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, S, a[35], b[35], mi;
bool found;

void Try(int x, int sum, int count, int start) {
    if (sum > S || count >= mi) return;
    if (sum == S) {
        found = true;
        mi = count;
        return;
    }
    for (int i = start; i < n; i++) {
        Try(x + 1, sum + a[i], count + 1, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> S;
        for (int i = 0; i < n; i++) cin >> a[i];

        mi = 50;
        found = false;

        sort(a, a + n, greater<int>()); // Sắp xếp giảm dần để tối ưu

        Try(0, 0, 0, 0);

        if (!found)
            cout << -1 << endl;
        else
            cout << mi << endl;
    }
}
