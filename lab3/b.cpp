#include <iostream>

using namespace std;

long long bin_search(long long * a, long long n, long long mid, long long k){
    long long cnt = 0;
    long long sum = 0;

    for(long long i = 0; i < n; i++){
        if(a[i] > mid){
            return false;
        } else if(sum + a[i] > mid){
            sum = a[i];
            cnt++;
        } else {
            sum += a[i];
        }
    }
    cnt++;
    return cnt <= k;
}


int main(){
    long long n, k;
    cin >> n >> k;
    long long l = 0;
    long long r = 0;
    long long result;
    long long a[n];

    for(long long i = 0; i < n; i++){
        cin >> a[i];
        r += a[i];
    }


    while(l <= r){
        long long mid =(r + l) / 2;

        if(bin_search(a, n, mid, k)){
            result = mid;
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    cout << result;

    return 0;
}