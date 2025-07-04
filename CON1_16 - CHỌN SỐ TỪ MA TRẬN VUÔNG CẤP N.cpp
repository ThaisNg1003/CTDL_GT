#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int b[n + 1][n + 1];
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];
    while (1)
    {
        int x = 0;
        for (int i = 1; i <= n; i++)
            x += b[i][a[i]];
        if (x == k)
            ans.push_back(a);
        int ok = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                ok = 1;
                sort(a.begin() + i + 1, a.end());
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (ok == 0)
            break;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 1; j <= n; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}