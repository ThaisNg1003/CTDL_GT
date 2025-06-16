#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Nut {
    int giaTri;
    Nut* trai;
    Nut* phai;
    Nut(int x) {
        giaTri = x;
        trai = NULL;
        phai = NULL;
    }
};

Nut* taoCay(vector<int> mang) {
    if (mang.size() == 0 || mang[0] == -1) return NULL;
    Nut* goc = new Nut(mang[0]);
    queue<Nut*> hangdoi;
    hangdoi.push(goc);
    int i = 1;
    while (!hangdoi.empty() && i < mang.size()) {
        Nut* hienTai = hangdoi.front();
        hangdoi.pop();
        if (i < mang.size() && mang[i] != -1) {
            hienTai->trai = new Nut(mang[i]);
            hangdoi.push(hienTai->trai);
        }
        i++;
        if (i < mang.size() && mang[i] != -1) {
            hienTai->phai = new Nut(mang[i]);
            hangdoi.push(hienTai->phai);
        }
        i++;
    }
    return goc;
}

int doSauNhoNhat(Nut* nut) {
    if (nut == NULL) return 0;
    if (nut->trai == NULL && nut->phai == NULL) return 1;
    if (nut->trai == NULL) return 1 + doSauNhoNhat(nut->phai);
    if (nut->phai == NULL) return 1 + doSauNhoNhat(nut->trai);
    int trai = doSauNhoNhat(nut->trai);
    int phai = doSauNhoNhat(nut->phai);
    return 1 + min(trai, phai);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> mang(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if (s == "null" || s == "-1") {
                mang[i] = -1;
            } else {
                mang[i] = stoi(s);
            }
        }
        Nut* goc = taoCay(mang);
        cout << doSauNhoNhat(goc) << endl;
    }
    return 0;
}
