#include <iostream>

using namespace std;

int bin_search(int * a, int n, int k){
    int l = 0, r = n - 1;

    while(l <= r){
        int mid = (l + r) / 2;

        if(a[mid] == k){
            return mid;
        } else if(a[mid] < k){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main(){

    int n, k, sum = 0;
    cin >> n >> k;
    int a[n], b[k];

    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        a[i] = sum;
    }

    for(int i = 0; i < k; i++){
        cin >> b[i];
        cout << bin_search(a, n, b[i]) + 1 << endl;
    }

    return 0;
}