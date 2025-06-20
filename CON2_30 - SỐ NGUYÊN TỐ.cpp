#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, p, ss;
vector<int> a, x;
vector<bool> check(205, 1);
vector<vector<int>> ans;
void era()
{
    for (int i = 2; i <= 200; i++)
    {
        if (check[i])
        {
            a.push_back(i);
            for (int j = i * i; j <= 200; j += i)
                check[j] = 0;
        }
    }
    m = a.size() - 1;
}
void Try(int pos, int k, int s)
{
    for (int i = pos + 1; i <= m; i++)
    {
        if (s + a[i] == ss && k == n - 1)
        {
            x.push_back(a[i]);
            ans.push_back(x);
            x.pop_back();
        }
        else if (k < n - 1 && s + a[i] < ss)
        {
            x.push_back(a[i]);
            Try(i, k + 1, s + a[i]);
            x.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    era();
    int t;
    cin >> t;
    while (t--)
    {
        ans.clear();
        cin >> n >> p >> ss;
        int b = 0;
        while (a[b] <= p)
            b++;
        Try(b - 1, 0, 0);
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}