#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string sapxep(vector<int> &A) {
    int n = A.size();
    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    
    for (int i = 0; i < n / 2; i++) {
        if (A[i] > A[i + 1]) {
            reverse(A.begin() + i, A.begin() + n - i);
        }
    }
    
    return (A == sorted_A) ? "Yes" : "No";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << sapxep(A) << endl;
    }
    return 0;
}
