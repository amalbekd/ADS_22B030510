#include <iostream>
#include <string>

using namespace std;

struct Node {
    string bookName;
    Node* prev;
    Node* next;
};

void addFront(Node*& head, Node*& tail, string book) {

    Node* newNode = new Node;
    newNode->bookName = book;
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL) {
        tail = newNode;
    } else {
        head->prev = newNode;
    }

    head = newNode;
    cout << "ok" << endl;
}

void addBack(Node*& head, Node*& tail, string book) {

    Node* newNode = new Node;
    newNode->bookName = book;
    newNode->prev = tail;
    newNode->next = NULL;

    if (tail == NULL) {
        head = newNode;
    } else {
        tail->next = newNode;
    }

    tail = newNode;
    cout << "ok" << endl;
}

void eraseFront(Node*& head, Node*& tail) {

    if (head == NULL) {
        cout << "error" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }

    cout << temp->bookName << endl;
    delete temp;
}

void eraseBack(Node*& head, Node*& tail){

    if (tail == NULL) {
        cout << "error" << endl;
        return;
    }

    Node* temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }

    cout << temp->bookName << endl;
    delete temp;
}

void printFront(Node* head){
    if (head == NULL) {
        cout << "error" << endl;
    } else {
        cout << head->bookName << endl;
    }
}

void printBack(Node* tail){
    if (tail == NULL) {
        cout << "error" << endl;
    } else {
        cout << tail->bookName << endl;
    }
}

void clear(Node*& head, Node*& tail) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    cout << "ok" << endl;
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    string s;
    while (cin >> s) {
        if (s == "add_front") {
            string book;
            cin >> book;
            addFront(head, tail, book);
        } else if (s == "add_back") {
            string book;
            cin >> book;
            addBack(head, tail, book);
        } else if(s == "erase_front"){
            eraseFront(head, tail);
        } else if(s == "erase_back"){
            eraseBack(head, tail);
        } else if(s == "front"){
            printFront(head);
        } else if(s == "back"){
            printBack(tail);
        } else if(s == "clear"){
            clear(head, tail);
        } else if(s == "exit"){
            cout << "goodbye" << endl;
            break;
        }
    }

    return 0;
}