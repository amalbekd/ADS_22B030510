#include <bits/stdc++.h>
 
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        deque<int> q;
        vector<int> a(1001);
        for(int j = 1; j <= m; j++){
            q.push_back(j);
        }
        int j = 1;                    
        while(!q.empty()){
            int l = 0;
            while( l < j){             
                int x=q.front();
                q.pop_front();
                q.push_back(x);
                l++;
            }
            int x = q.front();        
            if(a[x]!=0){
                cout << -1 << endl;
                return 0;
            }
            a[x] = j;                 
            q.pop_front();         
            j++;                    
        }
        for(int j = 1; j <= m; j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
}