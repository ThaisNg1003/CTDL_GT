#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, K;
vector<int> A, ket_qua;
vector<vector<int>> danh_sach;

void quay_lui(int i, int tong) {
    if (tong > K) return;
    if (tong == K) {
        danh_sach.push_back(ket_qua);
        return;
    }
    for (int j = i; j < N; j++) {
        ket_qua.push_back(A[j]);
        quay_lui(j + 1, tong + A[j]);
        ket_qua.pop_back(); // quay lui
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> K;
        A.resize(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        sort(A.begin(), A.end()); // sắp xếp để đảm bảo thứ tự từ điển
        danh_sach.clear();
        ket_qua.clear();

        quay_lui(0, 0);

        if (danh_sach.empty()) {
            cout << -1;
        } else {
            for (auto ds : danh_sach) {
                cout << "[";
                for (int i = 0; i < ds.size(); i++) {
                    cout << ds[i];
                    if (i != ds.size() - 1) cout << " ";
                }
                cout << "] ";
            }
        }
        cout << endl;
    }
    return 0;
}
