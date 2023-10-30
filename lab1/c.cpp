#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s, t, s1="", t1="";
    cin >> s >> t;
    stack<char> st1, st2;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '#'){
            st1.push(s[i]);
        }else{
            st1.pop();
        }
    }

    for(int j = 0; j < t.size(); j++){
        if(t[j] != '#'){
            st2.push(t[j]);
        }else{
            st2.pop();
        }
    }

    while(!st1.empty()){
        s1+=st1.top();
        st1.pop();
    }

    while(!st2.empty()){
        t1+=st2.top();
        st2.pop();
    }

    if(s1 == t1){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}