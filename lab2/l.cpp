#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
};

int maxSubarraySum(Node* head){
    if (!head){
        return 0;
    }

    int maxEndingHere = head->data;
    int maxSoFar = head->data;

    Node * current = head->next;
    while (current != nullptr){
        maxEndingHere = max(current->data, maxEndingHere + current->data);
        maxSoFar = max(maxSoFar, maxEndingHere);
        current = current->next;
    }

    return maxSoFar;
}

int main(){

    int n;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0; i < n; i++){
        int val;
        cin >> val;

        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;

        if(!head){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int result = maxSubarraySum(head);
    cout << result << endl;

    while(head != NULL){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}