#include <bits/stdc++.h>
using namespace std;

vector<string> sinh_so_nguyen_thuy(int max_n) {
    queue<string> q;
    vector<string> res;

    q.push("4");
    q.push("5");

    while ((int)res.size() < max_n) {
        string half = q.front(); q.pop();
        string full = half + string(half.rbegin(), half.rend()); // Đối xứng
        res.push_back(full);

        // Thêm các tổ hợp tiếp theo cho nửa đầu
        if (half.length() * 2 + 2 <= 10) { // để tránh chuỗi quá dài
            q.push(half + "4");
            q.push(half + "5");
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    vector<int> queries(t);
    int max_query = 0;
    for (int i = 0; i < t; i++) {
        cin >> queries[i];
        max_query = max(max_query, queries[i]);
    }

    vector<string> nguyen_thuy = sinh_so_nguyen_thuy(max_query);

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < queries[i]; j++) {
            cout << nguyen_thuy[j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
