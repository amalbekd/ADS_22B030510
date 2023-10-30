#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v;
    string l = "";

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        if(s != l){
            v.push_back(s);
        }

        l = s;
    }

    int num = v.size();
    reverse(v.begin(),v.end());

    cout << "All in all: " << num << endl;
    cout << "Students:" << endl;

    for(const string& s : v){
        cout << s << endl;
    }

    return 0;
}