#include <iostream>
using namespace std;

struct node {
    int val;
    int copies;  
    node* left;
    node* right;

    node(int x) : val(x), copies(1), left(NULL), right(NULL) {}
};

node* insert(node* root, int x) {
    if (!root) {
        return new node(x);
    }

    if (root->val == x) {
        root->copies++;  
    } else if (root->val < x) {
        root->right = insert(root->right, x);
    } else {
        root->left = insert(root->left, x);
    }
    return root;
}

node* delete_node(node* root, int x) {
    if (!root) return root;

    if (root->val == x) {
        root->copies--; 
        if (root->copies == 0) {
            if (!root->left) {
                node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                node* temp = root->left;
                delete root;
                return temp;
            }
            node* temp = root->right;
            while (temp && temp->left) temp = temp->left;
            root->val = temp->val;
            root->copies = temp->copies;
            temp->copies = 1;
            root->right = delete_node(root->right, temp->val);
        }
    } else if (root->val < x) {
        root->right = delete_node(root->right, x);
    } else {
        root->left = delete_node(root->left, x);
    }
    return root;
}

int cnt(node* root, int x) {
    if (!root) return 0;

    if (root->val == x) {
        return root->copies;
    } else if (root->val < x) {
        return cnt(root->right, x);
    } else {
        return cnt(root->left, x);
    }
}

int main() {
    node* root = NULL;
    int n;
    cin >> n;  
    

    while (n--) {
        string s;
        int x;
        cin >> s >> x;

        if (s == "insert") {
            root = insert(root, x);
        } else if (s == "delete") {
            root = delete_node(root, x);
        } else if (s == "cnt") {
            cout << cnt(root, x) << endl;
        }
    }
}