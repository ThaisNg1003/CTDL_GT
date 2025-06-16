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

        if (mang[i] != -1) {
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

void duyetCapDo(Nut* goc) {
    if (!goc) return;

    queue<Nut*> hangDoi;
    hangDoi.push(goc);

    while (!hangDoi.empty()) {
        int soNutTrongCap = hangDoi.size();

        for (int i = 0; i < soNutTrongCap; ++i) {
            Nut* hienTai = hangDoi.front();
            hangDoi.pop();
            cout << hienTai->giaTri << " ";

            if (hienTai->trai) hangDoi.push(hienTai->trai);
            if (hienTai->phai) hangDoi.push(hienTai->phai);
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
            cin >> mang[i];
        }

        Nut* goc = taoCay(mang);
        duyetCapDo(goc);
    }

    return 0;
}