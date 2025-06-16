#include <iostream>
#include <vector>
using namespace std;

void xuat_tam_giac(vector<int> a) {
    vector<vector<int>> tam_giac;
    tam_giac.push_back(a);
    while (a.size() > 1) {
        vector<int> hang_moi;
        for (size_t i = 0; i < a.size() - 1; i++) {
            hang_moi.push_back(a[i] + a[i + 1]);
        }
        tam_giac.push_back(hang_moi);
        a = hang_moi;
    }
    for (int i = tam_giac.size() - 1; i >= 0; i--) {
        cout << "[";
        for (size_t j = 0; j < tam_giac[i].size(); j++) {
            cout << tam_giac[i][j];
            if (j != tam_giac[i].size() - 1) cout << " ";
        }
        cout << "] ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        xuat_tam_giac(a);
    }
    return 0;
}
