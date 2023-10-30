#include <iostream>
#include <cmath>

using namespace std;

struct node{
    int data;
    node * next;
    node(){
        this->data = 0;
        this->next = NULL;
    }

    node(int data){
        this->data = data;
        this->next = NULL;
    }

    node(int data, node * next){
        this->data = data;
        this->next = next;
    }

};

struct Linkedlist{
    node * head;
    node * tail;
    Linkedlist(){
        head = NULL;
        tail = NULL;
    }

    void add_node(int x){
        node * temp = new node(x);
        if(head == NULL){
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void print(){
        node * temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main(){

    Linkedlist l;
    l.add_node(15);
    l.print();
    
    return 0;
}