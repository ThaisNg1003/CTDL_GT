#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> jobs(n);
    for (int i = 0; i < n; i++) cin >> jobs[i].first;
    for (int i = 0; i < n; i++) cin >> jobs[i].second;
    
    sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) { return a.second < b.second; });

    int res = 0, last = 0;
    for (auto &[s, f] : jobs) {
        if (s >= last) {
            res++;
            last = f;
        }
    }
    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
