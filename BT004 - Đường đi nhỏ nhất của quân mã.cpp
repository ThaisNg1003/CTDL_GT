#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int dijkstra(int n, vector<vector<int>>& a, int x1, int y1, int x2, int y2) {
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    
    dist[x1][y1] = a[x1][y1];
    pq.push({dist[x1][y1], x1, y1});

    while (!pq.empty()) {
        auto [d, x, y] = pq.top(); pq.pop();
        if (x == x2 && y == y2) return d;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                int cost = d + a[nx][ny];
                if (cost < dist[nx][ny]) {
                    dist[nx][ny] = cost;
                    pq.push({cost, nx, ny});
                }
            }
        }
    }
    return -1; // không tới được
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> a(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dijkstra(n, a, x1, y1, x2, y2) << endl;
    }
}
