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
        int n, k;
        cin >> n >> k;
        int a[k];
        for (int i = 0; i < k; i++)
            a[i] = i;
        stack<string> st;
        while (1)
        {
            string s = "";
            for (int i = 0; i < n; i++)
                s += '0';
            for (int i = 0; i < k; i++)
                s[a[i]] = '1';
            st.push(s);
            int ok = 0;
            for (int i = k - 1; i >= 0; i--)
            {
                if (a[i] != n - k + i)
                {
                    ok = 1;
                    a[i]++;
                    for (int j = i + 1; j < k; j++)
                        a[j] = a[j - 1] + 1;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        while (st.size())
        {
            cout << st.top() << endl;
            st.pop();
        }
    }
}