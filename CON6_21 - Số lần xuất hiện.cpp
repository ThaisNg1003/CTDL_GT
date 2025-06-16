#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto x : freq) {
            v.push_back({x.first, x.second});
        }
        sort(v.begin(), v.end(), cmp);
        for (auto x : v) {
            for (int i = 0; i < x.second; i++) {
                cout << x.first << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
