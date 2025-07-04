#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int k, n, m, ok;
char b[4][4];
bool check[4][4];
vector<string> a;
map<string, int> c;
vector<pair<int, int>> p = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
void Try(int i1, int i2, string x)
{
    if (c[x] > 0)
    {
        cout << x << " ";
        ok = 1;
    }
    for (int i = 0; i < 8; i++)
    {
        int p1 = i1 + p[i].first;
        int p2 = i2 + p[i].second;
        if (p1 < n && p1 >= 0 && p2 < m && p2 >= 0 && !check[p1][p2])
        {
            check[p1][p2] = 1;
            Try(p1, p2, x + b[p1][p2]);
            check[p1][p2] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s = "";
        ok = 0;
        c.clear();
        cin >> k >> n >> m;
        a.resize(k);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
            c[a[i]]++;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> b[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                check[i][j] = 1;
                Try(i, j, s + b[i][j]);
                check[i][j] = 0;
            }
        if (ok == 0)
            cout << -1;
        cout << endl;
    }
}