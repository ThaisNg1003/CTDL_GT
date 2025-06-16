#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, x;
        cin >> n >> m;
        vector<int> c;
        for (int i = 0; i < n; i++) {
            cin >> x;
            c.push_back(x);
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            c.push_back(x);
        }
        sort(c.begin(), c.end());
        for (int i = 0; i < c.size(); i++) {
            cout << c[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
