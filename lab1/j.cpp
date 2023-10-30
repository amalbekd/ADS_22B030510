#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> dq;
    bool h = true;
    
    while(h){
        string s;
        cin >> s;
        if(s == "!"){
            h = false;
        } else if(s == "+"){
            int is;
            cin >> is;
            dq.push_front(is);
        } else if(s == "-"){
            int is;
            cin >> is;
            dq.push_back(is);
        } else if(s == "*"){
            if(dq.empty()){
                cout << "error" << endl;
            } else{
                cout << (dq.back() + dq.front()) << endl;
                if(dq.size() == 1){
                    dq.pop_front();
                } else{
                    dq.pop_front();
                
                    dq.pop_back();
                }
                
   
            }

        }
    }

}