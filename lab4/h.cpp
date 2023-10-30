#include <iostream>
#include <vector>
#include <stack>

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
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void modify_BST(node* root, vector<int>& result) {
    stack<node*> st;
    node* current = root;
    int cumulativeSum = 0;

    while (current || !st.empty()) {
        while (current) {
            st.push(current);
            current = current->right;
        }

        current = st.top();
        st.pop();

        cumulativeSum += current->val;
        result.push_back(cumulativeSum);

        current = current->left;
    }
}

int main() {
    int n;
    cin >> n;
    int rootValue;
    cin >> rootValue;
    node* root = new node(rootValue);

    for (int i = 1; i < n; i++) {
        int val;
        cin >> val;
        insert(root, val);
    }

    vector<int> result;
    modify_BST(root, result);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}