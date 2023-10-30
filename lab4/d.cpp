#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
     value = val;
     left = right = NULL;
    } 
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
    return root;
}

int Max(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftLevel = Max(root->left);
    int rightLevel = Max(root->right);
    return max(leftLevel, rightLevel) + 1;
}

void level_sums(Node* root, int level, vector<int>& levelSums) {
    if (root == NULL) {
        return;
    }
    levelSums[level] += root->value;
    level_sums(root->left, level + 1, levelSums);
    level_sums(root->right, level + 1, levelSums);
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    Node* root = NULL;
    for (int i = 0; i < n; ++i) {
        root = insert(root, p[i]);
    }

    int maxLevel = Max(root);
    vector<int> levelSums(maxLevel, 0);
    level_sums(root, 0, levelSums);

    cout << maxLevel << endl;
    for (int i = 0; i < maxLevel; ++i) {
        cout << levelSums[i] << " ";
    }

    return 0;
}