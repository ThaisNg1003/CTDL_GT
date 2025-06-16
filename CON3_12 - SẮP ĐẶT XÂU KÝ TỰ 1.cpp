#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int sapXepXau(string s) {
    vector<int> dem(26, 0);
    for (char c : s) dem[c - 'a']++;
    int n = s.length();
    int lonNhat = *max_element(dem.begin(), dem.end());
    if (lonNhat > (n + 1) / 2) return -1;
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << sapXepXau(s) << endl;
    }
    return 0;
}
