#include<iostream>
using namespace std;

struct node{
    int value;
    node *left;
    node *right;

    node(int x) : value(x), left(NULL), right(NULL) {}

};
node* insert(node* root, int x){
    if(!root)
        return new node(x);
    if(x < root->value){
        root->left = insert(root->left, x);
    }
    else
        root->right = insert(root->right, x);
    return root;
}
int count(node* root){
    if(!root)
    return 0;
    if(root->left && root->right){
        return 1 + count(root->left) + count(root->right);
    }
    return count(root->left) + count(root->right);
}
int main(){
    int n;
    cin >> n;
    node*root = NULL;
    while(n--){
        int x;
        cin >> x;
        root = insert(root, x);
    }
    cout << count(root);
}
