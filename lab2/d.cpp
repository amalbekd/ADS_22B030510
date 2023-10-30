#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = NULL;

    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void printMode(Node* head) {
    vector<int> frequencies(1001, 0); 
    int maxFrequency = 0;

    while (head) {
        frequencies[head->data]++;
        maxFrequency = max(maxFrequency, frequencies[head->data]);
        head = head->next;
    }

    for (int i = 1000; i >= 1; i--) {
        if (frequencies[i] == maxFrequency) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    
    int n;
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        head = insertAtEnd(head, num);
    }

    printMode(head);

    return 0;
}