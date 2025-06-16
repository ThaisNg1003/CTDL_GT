#include <iostream>
#include <algorithm>
using namespace std;

int T;
int so[5];
char phep_toan[3] = {'+', '-', '*'};

int tinh(int a, char o, int b) {
    if (o == '+') return a + b;
    if (o == '-') return a - b;
    return a * b;
}

bool thu(int a, int b, int c, int d, int e) {
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    for (int k = 0; k < 3; k++)
    for (int l = 0; l < 3; l++) {
        int ket_qua = tinh(tinh(tinh(tinh(a, phep_toan[i], b), phep_toan[j], c), phep_toan[k], d), phep_toan[l], e);
        if (ket_qua == 23) return true;
    }
    return false;
}

int main() {
    cin >> T;
    while (T--) {
        for (int i = 0; i < 5; i++) cin >> so[i];
        bool tim_duoc = false;
        sort(so, so + 5);
        do {
            if (thu(so[0], so[1], so[2], so[3], so[4])) {
                tim_duoc = true;
                break;
            }
        } while (next_permutation(so, so + 5));
        cout << (tim_duoc ? "YES" : "NO") << endl;
    }
    return 0;
}
