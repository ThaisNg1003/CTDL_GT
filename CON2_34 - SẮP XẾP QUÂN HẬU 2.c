#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int T;
int ban_co[8][8];
int vi_tri[8];
int diem_cao_nhat;

bool hop_le(int hang, int cot) {
    for (int i = 0; i < hang; i++) {
        if (vi_tri[i] == cot || abs(vi_tri[i] - cot) == abs(i - hang)) {
            return false;
        }
    }
    return true;
}

void thu(int hang, int tong_diem) {
    if (hang == 8) {
        diem_cao_nhat = max(diem_cao_nhat, tong_diem);
        return;
    }
    for (int cot = 0; cot < 8; cot++) {
        if (hop_le(hang, cot)) {
            vi_tri[hang] = cot;
            thu(hang + 1, tong_diem + ban_co[hang][cot]);
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> ban_co[i][j];
        diem_cao_nhat = 0;
        thu(0, 0);
        cout << diem_cao_nhat << endl;
    }
    return 0;
}
