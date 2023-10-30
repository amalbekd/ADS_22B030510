#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    string a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        int solve = (i + k) % n;
        cout << a[solve] << " ";
    }

    return 0;
}