#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool f1(int n, int k, vector<int>& arr, int minLength) {
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];

        if(i >= minLength - 1 and sum >= k){
            return true;
        }

        if(i >= minLength - 1){
            sum -= arr[i - (minLength - 1)];
        }
    }

    return false;
}

int f2(int n, int k, vector<int>& arr) {
    int left = 1, right = n;
    int result = n + 1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(f1(n, k, arr, mid)){
            result = min(result, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << f2(n, k, arr) << endl;

    return 0;
}