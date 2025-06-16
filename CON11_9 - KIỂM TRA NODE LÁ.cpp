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

// Hàm kiểm tra các node lá có cùng mức không
bool checkSameLevelLeaf(Node* root) {
    if (!root) return true;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int leafLevel = -1;

    while (!q.empty()) {
        Node* node = q.front().first;
        int level = q.front().second;
        q.pop();

        if (!node->left && !node->right) {
            if (leafLevel == -1) leafLevel = level;
            else if (leafLevel != level) return false;
        }
        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
    }
    return true;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
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

        cout << (checkSameLevelLeaf(root) ? 1 : 0) << '\n';
    }
    return 0;
}
