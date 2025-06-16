#include <iostream>
using namespace std;

int n, k, s, dem;

void thu(int i, int so_phan_tu, int tong) {
    if (so_phan_tu == k && tong == s) {
        dem++;
        return;
    }
    if (so_phan_tu > k || tong > s || i > n) return;
    thu(i + 1, so_phan_tu + 1, tong + i);
    thu(i + 1, so_phan_tu, tong);
}

int main() {
    while (true) {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0) break;
        dem = 0;
        thu(1, 0, 0);
        cout << dem << endl;
    }
    return 0;
}
