#include <iostream>
#include <vector>
#include <queue>

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

int tree_width(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int maxWidth = 0;

    queue<Node*> levelQueue;
    levelQueue.push(root);

    while (!levelQueue.empty()) {
        int levelSize = levelQueue.size();
        maxWidth = max(maxWidth, levelSize);

        for (int i = 0; i < levelSize; i++) {
            Node* current = levelQueue.front();
            levelQueue.pop();

            if (current->left) {
                levelQueue.push(current->left);
            }
            if (current->right) {
                levelQueue.push(current->right);
            }
        }
    }

    return maxWidth;
}

int main() {
    int n;
    cin >> n;

    vector<Node*> nodes(n + 1, NULL);
    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (!nodes[x]) {
            nodes[x] = new Node(x);
        }
        if (!nodes[y]) {
            nodes[y] = new Node(y);
        }

        if (z == 0) {
            nodes[x]->left = nodes[y];
        } else {
            nodes[x]->right = nodes[y];
        }
    }

    int maxWidth = tree_width(nodes[1]);

    cout << maxWidth << endl;

    for (int i = 1; i <= n; i++) {
        delete nodes[i];
    }

    return 0;
}