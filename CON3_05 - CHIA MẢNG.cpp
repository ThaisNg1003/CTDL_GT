#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

void xu_ly() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    ll tong = 0, tong_nho = 0;
    for (int x : a) tong += x;
    for (int i = 0; i < k; i++) tong_nho += a[i];
    ll hieu1 = abs(tong - 2 * tong_nho);
    tong_nho = 0;
    for (int i = 0; i < n - k; i++) tong_nho += a[i];
    ll hieu2 = abs(tong - 2 * tong_nho);
    cout << max(hieu1, hieu2) << "\n";
}
int main() {
    int t;
    cin >> t;
    while (t--) xu_ly();
    return 0;
}
