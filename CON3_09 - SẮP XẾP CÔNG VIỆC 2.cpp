#include <bits/stdc++.h>
using namespace std;

void xu_ly() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> cong_viec(n);
    for (auto &[id, han, loi] : cong_viec) cin >> id >> han >> loi;
    
    sort(cong_viec.begin(), cong_viec.end(), [](auto &a, auto &b) { return get<2>(a) > get<2>(b); });

    vector<bool> lich(1001, false);
    int dem = 0, tong_loi = 0;

    for (auto &[id, han, loi] : cong_viec) {
        for (int j = min(han, 1000); j > 0; j--) {
            if (!lich[j]) {
                lich[j] = true;
                dem++;
                tong_loi += loi;
                break;
            }
        }
    }
    cout << dem << " " << tong_loi << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) xu_ly();
}
