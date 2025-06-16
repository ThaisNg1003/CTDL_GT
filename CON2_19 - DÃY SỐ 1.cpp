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
    for (auto &hang : tam_giac) {
        cout << "[";
        for (size_t i = 0; i < hang.size(); i++) {
            cout << hang[i];
            if (i != hang.size() - 1) cout << " ";
        }
        cout << "]\n";
    }
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
