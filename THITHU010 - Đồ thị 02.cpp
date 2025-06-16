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
    if (pu == pv) return false;
    parent[pv] = pu;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> edges(n);
        vector<int> parent(n + 1, 0);
        pair<int, int> edge1 = {-1, -1}, edge2 = {-1, -1};

        for (int i = 0; i < n; i++) {
            cin >> edges[i].first >> edges[i].second;
        }

        // Bước 1: Tìm đỉnh có 2 cha
        for (auto [u, v] : edges) {
            if (parent[v] == 0)
                parent[v] = u;
            else {
                edge1 = {parent[v], v};
                edge2 = {u, v};
                break;
            }
        }

        // Bước 2: Kiểm tra chu trình bằng Union-Find
        vector<int> dsu(n + 1);
        iota(dsu.begin(), dsu.end(), 0);
        bool hasCycle = false;

        for (auto [u, v] : edges) {
            if (make_pair(u, v) == edge2) continue; // bỏ edge2 để test
            if (!unionSets(dsu, u, v)) {
                hasCycle = true;
                break;
            }
        }

        // Bước 3: Quyết định cạnh cần loại
        if (edge1.first == -1 && edge2.first == -1) {
            // không có đỉnh nào có 2 cha → có chu trình
            vector<int> dsu2(n + 1);
            iota(dsu2.begin(), dsu2.end(), 0);
            for (auto [u, v] : edges) {
                if (!unionSets(dsu2, u, v)) {
                    cout << u << " " << v << endl;
                    break;
                }
            }
        } else {
            if (hasCycle)
                cout << edge1.first << " " << edge1.second << endl;
            else
                cout << edge2.first << " " << edge2.second << endl;
        }
    }
}
