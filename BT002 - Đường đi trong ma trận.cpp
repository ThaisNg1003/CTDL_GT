#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> Node;

int dx[] = {-1, 1, 0, 0}; // Lên, xuống, trái, phải
int dy[] = {0, 0, -1, 1};

int dijkstra(vector<vector<int>>& a, int m, int n, int x1, int y1, int x2, int y2) {
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    dist[x1][y1] = a[x1][y1];
    pq.push({dist[x1][y1], {x1, y1}});
    
    while (!pq.empty()) {
        auto [cost, pos] = pq.top(); pq.pop();
        int x = pos.first, y = pos.second;

        if (x == x2 && y == y2) return cost;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                int new_cost = cost + a[nx][ny];
                if (new_cost < dist[nx][ny]) {
                    dist[nx][ny] = new_cost;
                    pq.push({new_cost, {nx, ny}});
                }
            }
        }
    }
    return -1;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int m, n; cin >> m >> n;
        vector<vector<int>> a(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // Chuyển về chỉ số mảng 0-index
        cout << dijkstra(a, m, n, x1 - 1, y1 - 1, x2 - 1, y2 - 1) << endl;
    }
}
