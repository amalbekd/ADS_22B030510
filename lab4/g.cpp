#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct node {

    int value;
    node* left;
    node* right;

    node(int val) : value(val), left(NULL), right(NULL) {}
};

node* insert(node* root, int x){
    if(root == NULL){
        return new node(x);
    }

    if(x < root->value){
        root->left = insert(root->left, x);
    }
    else{
        root->right = insert(root->right, x);
    }

    return root;
}

int height(node *root, int& res) {
    if (root == NULL)
        return 0;
    int left = height(root->left, res);
    int right = height(root->right, res);
    res = max(res, left + right);
    return 1 + max(left, right);
}

int width(node *root) {
    int res = 0;
    height(root, res);
    return res;
}


int main() {
    int n; 
    cin >> n;
    node *root = NULL;

    map<int, int> dict;
    for(int i = 0; i < n; i++) {
        int temp; 
        cin >> temp;
        dict[temp]++;
        if(dict[temp] == 1){
            root = insert(root, temp);
        }
    }
    cout << width(root) + 1;
}