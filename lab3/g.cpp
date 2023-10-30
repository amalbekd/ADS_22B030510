#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int bin_search(int * a, int n, int k){
    int l = 1, r = a[n - 1];
    int mid;

    while (l < r){
        int sum = 0;
        mid = (l + r) / 2;
        for(int i = 0; i < n; i++){
            sum += ceil(1.0 * a[i] / mid);
        }

        if(sum > k){
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    return r;
}

int main(){

    int n, k;
    cin >> n >> k;
    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    cout << bin_search(a, n, k);
    

    return 0;
}