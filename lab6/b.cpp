#include <iostream>
#include <vector>

using namespace std;

void cussort(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0;  j < v.size() -1; j++){
            if(v[j] > v[j+ 1]){
                
                swap(v[j], v[j+1]);
            }
        }
    
    }

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> a;
    vector<int> b;
    vector<int> v;

    int x;
    for(int i = 0; i < n; i++){
        
        cin >> x;
        a.push_back(x);
    }

    for(int i = 0; i < m; i++){
        cin >> x;
        b.push_back(x);
    }
    

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j]){
                v.push_back(a[i]);
                a.erase(a.begin() + i);
                b.erase(b.begin() + j);
                i--;
                j--;
                break;
                
            }
        }
    }

    cussort(v);

    return 0;
}