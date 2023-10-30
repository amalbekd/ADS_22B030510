#include <iostream>

using namespace std;

bool bin_search(int * a, int n, int k){

    bool cnt = false;

    int l = 0;
    int r = n - 1;

    while(l <= r){

        int m = (l + r) / 2;

        if(a[m] == k){
            cnt = true;
            break;
        }

        if(a[m] > k){
            r = m - 1;
        } else {
            l = m + 1;
        }
        
    }

    return cnt;

}


int main(){

    int n, k;
    cin >> n;;
    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cin >> k;

    if(bin_search(a, n, k)){
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}