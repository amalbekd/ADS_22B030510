#include <iostream>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string cons(string c){
        for (int i = 0; i < c.size() - 1; i++) {
        for (int j = 0; j < c.size() - i - 1; j++) {
            if (c[j] > c[j + 1]) {
                swap(c[j], c[j + 1]);
            }
        }
    }
    return c;
}
string vow(string v){

        for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
    return v;
}

string letters(string v, string c){
    for(int j = 0; j < v.size() - 1; j++){
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] > v[i + 1]){
            swap(v[i], v[i + 1]);
        }
    }
    }

    for(int j = 0; j < c.size() - 1; j++){
    for(int i = 0; i < c.size() - 1; i++){
        if(c[i] > c[i + 1]){
            swap(c[i], c[i + 1]);
        }
    }
    }

    return v + c;
}

string cussort(string s){
    string v = ""; 
    string c = "";
    for(int i = 0; i < s.size(); i++){
        if(isVowel(s[i])){
            v += s[i];
        }
        else {
            c += s[i];
        }
    }
    

    if(v == ""){
        return cons(c);    
    } else if(c == ""){
        return vow(v);
    } else {
        return letters(v, c);
    }
}

int main(){

    int n;
    string s;
    cin >> n >> s;

    cout << cussort(s);

    return 0;
}