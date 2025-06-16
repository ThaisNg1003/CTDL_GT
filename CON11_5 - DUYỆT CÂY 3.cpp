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

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->data << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
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
        // tìm gốc: là node không phải là con
        Node* root = nullptr;
        for (auto& it : nodes) {
            if (children.find(it.first) == children.end()) {
                root = it.second;
                break;
            }
        }
        levelOrder(root);
        cout << '\n';
    }
    return 0;
}
