#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string Try(string s)
{
    string k, ans = "";
    char c, d;
    stack<char> st, ld;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
            ld.push(s[i - 1]);
        }
        else if (s[i] == ')')
        {
            k = "";
            while (st.size())
            {
                c = st.top();
                st.pop();
                d = st.top();
                st.pop();
                if (ld.top() == '-')
                {
                    k = c + k;
                    if (d == '-')
                        k = '+' + k;
                    else
                        k = '-' + k;
                }
                else
                {
                    k = c + k;
                    k = d + k;
                }
                if (d == '(')
                {
                    for (int j = 1; j < k.size(); j++)
                        st.push(k[j]);
                    break;
                }
            }
            ld.pop();
        }
        else
            st.push(s[i]);
    }
    while (st.size())
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        a = Try(a);
        b = Try(b);
        if (a == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}