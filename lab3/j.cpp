#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int result(double * a, int n, int h){
    int l = 1, r = a[n - 1];
    int mid;
    while (l < r){
        int sum = 0;
        mid = l + (r - l)/2;
        
        for(int i = 0; i < n; i++){
            
            sum += ceil(a[i] / mid);
        }
        if(sum > h){
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    return r;
}





int main(){

    int n, h; 
    cin >> n >> h;

    double a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    cout << result(a, n, h);

    return 0;
}