#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int k;
    cin >> k;

    int max = 100000000;
    int mndis = -1;

    for(int i = 0; i < n; i++){
        int distance = abs(v[i] - k);
        if(distance < max){
            max = distance;
            mndis = i;
        }
    }

    cout << mndis << endl;

    return 0;
}