#include <iostream>
#include <algorithm>

using namespace std;

int f(int * a, int n, int k, bool side){
    int l = 0;
    int r = n - 1;

    while(l <= r){
        int mid = (r + l) / 2;

        if(a[mid] == k){
            return mid;
        } else if(a[mid] < k){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if(side){
        return r;
    } else {
        return l;
    }
}


int main(){
    int n, m; 
    cin >> n >> m;

    int a[n]; 
    int b[m][4];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < 4; j++){
            cin >> b[i][j];
        }
    }

    sort(a, a + n);

    for(int i = 0; i < m; i++){
        int l1 = b[i][0], r1 = b[i][1], l2 = b[i][2] , r2 = b[i][3];

        bool inter = max(l1, l2) <= min(r1, r2); 
        
        if(inter){
            cout << f(a, n, max(r1, r2), true) - f( a, n, min(l1, l2), false) + 1;
        } else {
            cout << (f( a, n, r1, true) + f( a, n, r2, true) + 2) - (f(a, n, l1, false) + f(a, n, l2, false));
        }

        cout << endl;
    }
    
    return 0;

    
}