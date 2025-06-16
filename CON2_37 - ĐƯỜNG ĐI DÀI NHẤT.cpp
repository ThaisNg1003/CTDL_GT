#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T, n, m, ket_qua;
vector<pair<int, int>> ke[21];
bool da_di[21][21];

void dfs(int u, int do_dai) {
    ket_qua = max(ket_qua, do_dai);
    for (auto it : ke[u]) {
        int v = it.first;
        if (!da_di[u][v]) {
            da_di[u][v] = da_di[v][u] = true;
            dfs(v, do_dai + 1);
            da_di[u][v] = da_di[v][u] = false;
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) ke[i].clear();
        memset(da_di, false, sizeof(da_di));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            ke[u].push_back({v, 1});
            ke[v].push_back({u, 1});
        }
        ket_qua = 0;
        for (int i = 0; i < n; i++) {
            dfs(i, 0);
        }
        cout << ket_qua << endl;
    }
    return 0;
}
