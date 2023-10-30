#include <iostream>
#include <map>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

struct Node{
    string val;
    struct Node* next;
    struct Node* prev;
    bool there;
    Node(string _val): val(_val), next(nullptr), prev(nullptr), there(false) {}
};

struct list{
    Node* head;
    Node* tail;

    list(): head(nullptr), tail(nullptr) {}

    bool isEmpty(){
        return head == nullptr;
    }


    void pop_front(){
        if(isEmpty()){
            cout<<"error";
            return;
        }else if(tail == head){
            cout<<head->val;
            head = head->next;
        }else {
            cout << head->val;
            head = head->next;
            head->prev = nullptr;
        }
    }
    void pop_back(){
        if(isEmpty()){
            cout<<"error";
            return;
        }else if(tail == head){
            cout<<head->val;
            head = head->next;
        }else{
            cout<<tail->val;
            Node* p = tail->prev;
            p->next = nullptr;
            tail->prev = nullptr;
            tail = p;
        }

    }

    void front(){
        if(isEmpty()){
            cout<<"error";
            return;
        }
        cout<<head->val;
    }
    void back(){
        if(isEmpty()){
            cout<<"error";
            return;
        }
        cout<<tail->val;
    }

    void clear(){
        Node* temp = new Node(0);

        while(head){
            temp = head;
            head = head->next;
            free(temp);
        }

        cout<<"ok";

    }


    void show(){
        if(isEmpty()) return;
        Node* p = head;
        while(p){
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
    }

    void showEven(){
        Node* p = head;
        int i = 0;
        while(p){
            if(i%2==0){
                cout<<p->val<<" ";

            }
            p = p->next;
            i++;
        }
        cout<<endl;
    }




    void one_time(){
        Node* cur = head;
        while(cur){
            if(!cur->there){
                cout<<cur->val<<" ";
                return;
            }

            cur = cur->next;
        }
        cout<<-1<<" ";
    }

    void push(string _val){
        Node* p = new Node(_val);
        if(isEmpty()){
            head = p;
            tail = p;
            return;
        }else{
            Node* cur = head;
            while(cur){
                if(cur->val == _val){
                    cur->there = true;
                    return;
                }
                cur = cur->next;
            }

            tail->next = p;
            tail = p;
        }
    }
};
int main(){

    int n; 
    cin >> n;

    for(int i = 0; i < n; i++){
        list l;
        int m; 
        cin >> m; 

        for(int j = 0; j < m; j++){
            string s;
            cin >> s;
            l.push(s);
            l.one_time();
        }
        cout<<endl;
    }

    return 0;
}