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

void duyet(Nut* nut, int tong, int mucTieu, vector<int>& duong, vector<vector<int>>& ketQua) {
    if (!nut) return;
    duong.push_back(nut->giaTri);
    tong += nut->giaTri;
    if (!nut->trai && !nut->phai && tong == mucTieu) ketQua.emplace_back(duong);
    else {
        if (nut->trai) duyet(nut->trai, tong, mucTieu, duong, ketQua);
        if (nut->phai) duyet(nut->phai, tong, mucTieu, duong, ketQua);
    }
    duong.pop_back();
}

void xuLy(const vector<int>& mang, int mucTieu) {
    Nut* goc = taoCay(mang);
    vector<vector<int>> ketQua;
    vector<int> duong;
    duyet(goc, 0, mucTieu, duong, ketQua);
    if (ketQua.empty()) cout << "0\n";
    else {
        for (const auto& d : ketQua) {
            cout << "[";
            for (int i = 0; i < d.size(); ++i) {
                cout << d[i];
                if (i + 1 < d.size()) cout << ",";
            }
            cout << "]";
        }
        cout << endl;
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
            string s;
            cin >> s;
            if (s == "null" || s == "-1") mang[i] = -1;
            else mang[i] = stoi(s);
        }
        int mucTieu;
        cin >> mucTieu;
        xuLy(mang, mucTieu);
    }
    return 0;
}
