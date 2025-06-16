#include <bits/stdc++.h>
using namespace std;

int tinhLCS(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // bỏ dòng thừa
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string a, b;
        ss >> a >> b;

        int lcs = tinhLCS(a, b);
        cout << a.size() + b.size() - lcs << endl;
    }
}
