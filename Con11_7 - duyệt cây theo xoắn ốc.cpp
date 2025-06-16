#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void spiralOrder(Node* root) {
    if (!root) return;
    stack<Node*> s1; // từ trái qua phải
    stack<Node*> s2; // từ phải qua trái
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* cur = s1.top(); s1.pop();
            cout << cur->data << " ";
            if (cur->left) s2.push(cur->left);
            if (cur->right) s2.push(cur->right);
        }
        while (!s2.empty()) {
            Node* cur = s2.top(); s2.pop();
            cout << cur->data << " ";
            if (cur->right) s1.push(cur->right);
            if (cur->left) s1.push(cur->left);
        }
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int, Node*> nodes;
        set<int> children;
        for (int i = 0; i < n; ++i) {
            int u, v;
            char ch;
            cin >> u >> v >> ch;
            if (!nodes[u]) nodes[u] = new Node(u);
            if (!nodes[v]) nodes[v] = new Node(v);
            if (ch == 'L') nodes[u]->left = nodes[v];
            else nodes[u]->right = nodes[v];
            children.insert(v);
        }
        // tìm gốc
        Node* root = nullptr;
        for (auto& it : nodes) {
            if (children.find(it.first) == children.end()) {
                root = it.second;
                break;
            }
        }
        spiralOrder(root);
        cout << '\n';
    }
    return 0;
}
