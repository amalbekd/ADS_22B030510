#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    int size;  
    Node(int val) : value(val), left(NULL), right(NULL), size(1) {}
};

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    root->size = 1 + (root->left ? root->left->size : 0) + (root->right ? root->right->size : 0);
    return root;
}

int find_subtree_size(Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (value == root->value) {
        return root->size;
    }
    if (value < root->value) {
        return find_subtree_size(root->left, value);
    } else {
        return find_subtree_size(root->right, value);
    }
}

int main() {
    int n, x;
    cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    cin >> x;
    int subtreeSize = find_subtree_size(root, x);

    cout << subtreeSize << endl;

    return 0;
}