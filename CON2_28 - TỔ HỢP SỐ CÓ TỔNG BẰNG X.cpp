#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct data
{
    vector<int> b;
};
int n, k, a[25], c[105];
vector<struct data> d;
void Try(int x, int i, int s)
{
    for (int ii = i; ii <= n; ii++)
    {
        s += a[ii];
        c[x] = a[ii];
        if (s == k)
        {
            struct data e;
            for (int jj = 1; jj <= x; jj++)
                e.b.push_back(c[jj]);
            d.push_back(e);
        }
        else if (s < k)
            Try(x + 1, ii, s);
        s -= a[ii];
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
        d.clear();
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(1, 1, 0);
        if (d.size() == 0)
        {
            cout << "-1" << endl;
            continue;
        }
        for (int i = 0; i < d.size(); i++)
        {
            cout << "[" << d[i].b[0];
            for (int j = 1; j < d[i].b.size(); j++)
            {
                if (d[i].b[j] == 0)
                    break;
                cout << " " << d[i].b[j];
            }
            cout << "]";
        }
        cout << endl;
    }
}