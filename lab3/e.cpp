#include <iostream>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    int l = 0, r = 0;
    int a[n][2];

    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i][0] = x2;
        a[i][1] = y2;
        r = max(max(x2, y2), r);
    }

    while(l < r){
        int cnt = 0;
        int mid = (l + r) / 2;

        for(int i = 0; i < n; i++){
            if(a[i][0] <= mid && a[i][1] <= mid){
                cnt++;
            }
        }

        if(cnt >= k){
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l;

    return 0;
}