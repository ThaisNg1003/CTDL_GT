#include <bits/stdc++.h>
using namespace std;

int tinhHauTo(string s) {
    stack<int> st;
    for (char c : s) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b); // chia lấy phần nguyên
        }
    }
    return st.top();
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s;
        cin >> s;
        cout << tinhHauTo(s) << '\n';
    }
    return 0;
}
