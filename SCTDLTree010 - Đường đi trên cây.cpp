#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Nut {
    int giaTri;
    Nut* trai;
    Nut* phai;
    Nut(int x) : giaTri(x), trai(nullptr), phai(nullptr) {}
};

Nut* taoCay(const vector<int>& mang) {
    if (mang.empty() || mang[0] == -1) return nullptr;
    Nut* goc = new Nut(mang[0]);
    queue<Nut*> hangDoi;
    hangDoi.push(goc);
    int i = 1;
    while (i < mang.size()) {
        Nut* hienTai = hangDoi.front();
        hangDoi.pop();
        if (i < mang.size() && mang[i] != -1) {
            hienTai->trai = new Nut(mang[i]);
            hangDoi.push(hienTai->trai);
        }
        i++;
        if (i < mang.size() && mang[i] != -1) {
            hienTai->phai = new Nut(mang[i]);
            hangDoi.push(hienTai->phai);
        }
        i++;
    }
    return goc;
}

void timDuong(Nut* nut, vector<int>& duong, vector<vector<int>>& ketQua) {
    if (!nut) return;
    duong.push_back(nut->giaTri);
    if (!nut->trai && !nut->phai) {
        ketQua.push_back(duong);
    } else {
        timDuong(nut->trai, duong, ketQua);
        timDuong(nut->phai, duong, ketQua);
    }
    duong.pop_back();
}

void xuLy(vector<int>& mang) {
    Nut* goc = taoCay(mang);
    vector<vector<int>> ketQua;
    vector<int> duong;
    timDuong(goc, duong, ketQua);
    if (ketQua.empty()) {
        cout << "0\n";
    } else {
        for (auto& d : ketQua) {
            for (int i = 0; i < d.size(); ++i) {
                cout << d[i];
                if (i < d.size() - 1) cout << "->";
            }
            cout << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> mang(n);
        for (int i = 0; i < n; ++i) {
            cin >> mang[i];
        }
        xuLy(mang);
    }
    return 0;
}
