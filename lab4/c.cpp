#include <iostream>

using namespace std;

struct node {
    int value;
    node* left;
    node* right;
    
    node(int val) : value(val), left(NULL), right(NULL) {}
};

node* insert(node* root, int value) {
    if (root == NULL) {
        return new node(value);
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

node* find_subtree(node* root, int k) {
    if (root == NULL || root->value == k) {
        return root;
    }
    
    if (k < root->value) {
        return find_subtree(root->left, k);
    }
    
    return find_subtree(root->right, k);
}

void print(node* root) {
    if (root) {
        cout << root->value << " ";
        print(root->left);
        print(root->right);
    }
}

int main() {
    int n;
    cin >> n;
    node* root = NULL;
    
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        root = insert(root, ai);
    }
    
    int k;
    cin >> k;
    
    node* subtreeRoot = find_subtree(root, k);
    
    print(subtreeRoot);
    
    return 0;
}