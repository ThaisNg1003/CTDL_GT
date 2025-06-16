#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int u) {
    if (parent[u] != u)
        parent[u] = find(parent, parent[u]);
    return parent[u];
}

bool unionSets(vector<int>& parent, int u, int v) {
    int pu = find(parent, u);
    int pv = find(parent, v);
    if (pu == pv) return false; // chu trình
    parent[pu] = pv;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> edges(n);
        for (int i = 0; i < n; i++) {
            cin >> edges[i].first >> edges[i].second;
        }

        vector<int> parent(1001); // 1 <= ai, bi <= 1000
        for (int i = 0; i < 1001; i++) parent[i] = i;

        pair<int, int> res;
        for (auto [u, v] : edges) {
            if (!unionSets(parent, u, v)) {
                res = {u, v}; // lưu lại cạnh gây chu trình
            }
        }

        cout << res.first << " " << res.second << endl;
    }
    return 0;
}
