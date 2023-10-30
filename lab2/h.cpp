#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};



Node* insert(Node* head, Node* node, int p){
    if(!head){
        head = node;
        if(p == 0){
            node->next = head;
            head->next = nullptr;
            head = node;
            return head;
        }
    } else if(head and p == 0){
        node->next = head;
        head = node;
        return head;
    } else {
        Node* cur = head;
        int i = 1;
        while(cur){
            if(i == p){
                node->next = cur->next;
                cur->next = node;
                return head;
            }
            cur = cur->next;
            i++;
        }
        return head;
    }
}

Node* remove(Node* head, int p){
    if(p == 0){
        return head->next;
    }else{
        int i = 0;
        Node* cur = head;
        Node* prev = nullptr;

        while(cur){
            if(i == p){
                prev->next = cur->next;
            }

            prev = cur;
            cur = cur->next;
            i++;
        }

        return head;
    }
}

Node* replace(Node* head, int p1, int p2){
    if(p1 == p2){
        return head;
    }else{
        Node* cur = head;
        int i = 0;

        while(cur){
            if(i == p1){
                head = remove(head, p1);
                head = insert(head, new Node(cur->val), p2);
            }
            cur = cur->next;
            i++;
        }

        return head;
    }
}


Node* reverse(Node* head){
    Node* cur = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while(cur){

        next = cur->next;

        cur->next = prev;

        prev = cur;

        cur = next;
    }

    return prev;

}

void print(Node* head){

    int i = 0;

    while(head){
        cout<<head->val<<" ";
        head = head->next;
        i++;
    }
    cout<<endl;
}



Node* cyclic_right(Node* head, int x){
    
    if(!head or x == 0){
        return head;
    }else{
        int len = 1;
        Node* cur = head;
        Node* last;
        while(cur->next){
            cur = cur->next;
            len++;
        }

        int shift_point = len - x;
        Node* temp;
        last = cur;
        cur = head;
        for(int i = 1; i < shift_point; i++){
           cur = cur->next;
        }
        temp = cur->next;
        last->next = head;
        head = temp;
        cur->next = nullptr;
        return head;
    }



}
Node* cyclic_left(Node* head, int x){
    if(!head){
        return head;
    }else{
        head = reverse(head);
        head = cyclic_right(head, x);
        head = reverse(head);
        return head;
    }
}
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }

    }
    return 0;
}