#include <iostream>
#include <cmath>

using namespace std;

struct node{
    int val;
    node * next;
    node(int val){
        this->val = val;
        this->next = NULL;
    }
};

struct linkedlist{
    node * head;
    node * tail;
    linkedlist(){
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
    void dif(int k){
        node * temp = head;
        int count = 0;
        int index;
        int mx = 10000000;
        while(temp!=NULL){
            int difference = abs(temp->val - k);

            if(difference < mx){
                mx = difference;
                index = count; 
            } 
            count++;  
            temp = temp->next;      
        }
        cout << index;

    }

    void print(){
        node * temp = head;
        while(temp != NULL){
            cout<<temp->val << " ";
            temp = temp->next;
        }
    }
};

int main(){
    linkedlist l;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        l.add_node(temp);
    }

    int k;
    cin >> k;

    l.dif(k);

    return 0;
}