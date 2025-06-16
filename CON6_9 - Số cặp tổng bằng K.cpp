#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, k;
        cin >> n >> k;
        
        int A[n];
        unordered_map<int, int> freq;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            freq[A[i]]++;
        }
        
        for (int i = 0; i < n; i++) {
            int target = k - A[i];
            freq[A[i]]--;
            if (freq[target] > 0) {
                count += freq[target];
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
