#include <bits/stdc++.h>
#define ll long long
#define II pair<int, int>
using namespace std;
map<int, II> brackets;
vector<string> configs;
string RemoveBracket(string s, string tmp) {
    vector<bool> dd(s.length(), true);
    for (int i = 0; i < tmp.length(); ++i) {
        if (tmp[i] == '0') {
            II bracket = brackets[i];
            dd[bracket.first] = dd[bracket.second] = false;
        }
    }
    string res = "";
    for (int i = 0; i < dd.size(); ++i) {
        if (dd[i] == true)
            res += s[i];
    }
    return res;
}
void BinGen(int index, string s) {
    if (index == s.length()) {
        configs.push_back(s);
        return;
    }
    for (int j = 0; j <= 1; ++j) {
        s[index] = j + '0';
        BinGen(index + 1, s);
    }
}
void TestCase() {
    string s; cin >> s;
    stack<II> st;
    int cnt = 0; 
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            brackets[cnt].first = i;
            st.push({cnt, i});
            cnt++;
        }
        else if (s[i] == ')') {
            int x = st.top().first;
            st.pop();
            brackets[x].second = i;
        }
    }
    string tmp = string(cnt, '0');
    BinGen(0, tmp);
    configs.pop_back(); 

    map<string, bool> res; 
    for (int i = 0; i < configs.size(); ++i) {
        string z = RemoveBracket(s, configs[i]);
        res[z] = true;
    }
    for (auto i : res) {
        cout << i.first << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 1;
    while (T--) {
        TestCase();
        cout << endl;
    }
    return 0;
}