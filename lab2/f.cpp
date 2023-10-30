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

    void insert_element(int el, int pos){
        node * temp = head;
        node * add = new node(el);
        int i = 0;
        while(i < pos - 1){
            temp = temp->next;
            i++;
        }

        if(pos == 0){

            add->next = temp;
            head = add;
            return;
        }

        add->next = temp->next;
        temp->next = add;
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

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        l.add_node(x);
    }
    int el, pos;
    cin >> el >> pos;

    l.insert_element(el, pos);
    l.print();
    
    return 0;
}