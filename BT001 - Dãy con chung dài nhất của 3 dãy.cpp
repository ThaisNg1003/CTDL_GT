#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int na, nb, nc;
        cin >> na;
        vector<int> A(na);
        for (int &x : A) cin >> x;
        cin >> nb;
        vector<int> B(nb);
        for (int &x : B) cin >> x;
        cin >> nc;
        vector<int> C(nc);
        for (int &x : C) cin >> x;

        int dp[101][101][101] = {};

        for (int i = 1; i <= na; ++i) {
            for (int j = 1; j <= nb; ++j) {
                for (int k = 1; k <= nc; ++k) {
                    if (A[i-1] == B[j-1] && B[j-1] == C[k-1])
                        dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                    else
                        dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                }
            }
        }

        cout << dp[na][nb][nc] << "\n";
    }
    return 0;
}
