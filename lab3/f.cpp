#include <iostream>

using namespace std;

int main(){

    int n, k, x;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cin >> k;
    for(int l = 0; l < k; l++){
        int cnt = 0, sum = 0;
        cin >> x;
        for(int i = 0; i < n; i++){
            if(a[i] <= x){
                cnt++;
                sum += a[i];
            }
        }
        cout << cnt << " " << sum << endl;
    }

    

    return 0;
}