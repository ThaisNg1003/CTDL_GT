#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<vector<int>> res;
vector<int> a;

void sinh(int sum, int last) {
    if (sum == n) {
        res.push_back(a);
        return;
    }
    for (int i = last; i >= 1; i--) {
        if (sum + i <= n) {
            a.push_back(i);
            sinh(sum + i, i);
            a.pop_back();
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        res.clear();
        a.clear();
        sinh(0, n);
        for (auto v : res) {
            cout << "(";
            for (int i = 0; i < v.size(); i++) {
                cout << v[i];
                if (i != v.size() - 1) cout << " ";
            }
            cout << ") ";
        }
        cout << "\n";
    }
    return 0;
}
