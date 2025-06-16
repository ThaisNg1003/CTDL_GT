#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    scanf("%d", &n);
    vector<ll> a(n), b(n);
    for (ll &x : a) scanf("%lld", &x);
    for (ll &x : b) scanf("%lld", &x);
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    ll res = 0;
    for (int i = 0; i < n; i++) res += a[i] * b[i];
    printf("%lld\n", res);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}