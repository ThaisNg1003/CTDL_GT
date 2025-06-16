#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string ket_qua_lon_nhat;

void doi_cho(string &s, int k, int bat_dau) {
    if (k == 0) return;
    int n = s.length();

    for (int i = bat_dau; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[j] > s[i]) {
                swap(s[i], s[j]);
                if (s > ket_qua_lon_nhat) ket_qua_lon_nhat = s;
                doi_cho(s, k - 1, i);
                swap(s[i], s[j]); // quay lui
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int K;
        string S;
        cin >> K >> S;
        ket_qua_lon_nhat = S;
        doi_cho(S, K, 0);
        cout << ket_qua_lon_nhat << endl;
    }
    return 0;
}
