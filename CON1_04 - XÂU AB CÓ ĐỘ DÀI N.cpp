#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a;
        for (int i = 0; i < n; i++)
            a += 'A';
        while (1)
        {
            cout << a << " ";
            int ok = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] == 'A')
                {
                    ok = 1;
                    a[i] = 'B';
                    for (int j = i + 1; j < n; j++)
                        a[j] = 'A';
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        cout << endl;
    }
}