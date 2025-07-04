#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, k;
        cin >> n >> m;
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        cin >> m;
        while (m--)
        {
            cin >> x >> y;
            queue<int> q;
            q.push(x);
            int ok = 0, check[n + 1] = {};
            while (q.size())
            {
                k = q.front();
                q.pop();
                if (k == y)
                {
                    ok = 1;
                    break;
                }
                for (int i = 0; i < a[k].size(); i++)
                {
                    if (!check[a[k][i]])
                    {
                        check[a[k][i]] = 1;
                        q.push(a[k][i]);
                    }
                }
            }
            if (ok)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}