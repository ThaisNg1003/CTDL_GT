#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, a[20], b[20] = {};
long long s = 1e15, c[20][20], S = 0;
void Try(int x)
{
    for (int i = 2; i <= n; i++)
    {
        if (b[i] == 0)
        {
            a[x] = i;
            b[i] = 1;
            S += c[a[x - 1]][i];
            if (x == n && S + c[i][1] < s)
                s = S + c[i][1];
            else if (S < s && x < n)
                Try(x + 1);
            S -= c[a[x - 1]][i];
            b[i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a[1] = 1;
    b[1] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    Try(2);
    cout << s;
}