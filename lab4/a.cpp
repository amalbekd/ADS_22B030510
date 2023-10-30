#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;

    node(int value) : val(value), left(NULL), right(NULL) {}
};

node* insert(node* root, int val) {
    if (root == NULL) {
        return new node(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

bool is_path_available(node* root, const string& path, int index) {
    if (index == path.length()) {
        return true;
    }

    char direction = path[index];
    if (direction == 'L') {
        if (root->left != NULL) {
            return is_path_available(root->left, path, index + 1);
        }
    } else if (direction == 'R') {
        if (root->right != NULL) {
            return is_path_available(root->right, path, index + 1);
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> directions(n);

    for (int i = 0; i < n; i++) {
        cin >> directions[i];
    }

    node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, directions[i]);
    }

    for (int i = 0; i < m; i++) {
        string path;
        cin >> path;
        if (is_path_available(root, path, 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}