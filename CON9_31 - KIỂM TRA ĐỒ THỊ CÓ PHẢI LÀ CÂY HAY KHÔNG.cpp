#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(1001);
bool visited[1001];
bool ok;

void dfs(int u, int parent) {
    visited[u] = true;
    for (int v : a[u]) {
        if (!visited[v]) {
            dfs(v, u);
        } else if (v != parent) {
            ok = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, u, v;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            a[i].clear();
            visited[i] = false;
        }
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        ok = false;
        dfs(1, -1);
        bool connected = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) connected = false;
        }
        if (!ok && connected)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
