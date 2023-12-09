#include <iostream>

using namespace std;

int main() {
    int n, k = 1e5, sum = 0;
    cin >> n; 
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k = min(k, a[i]);
        sum += a[i];
    }
    cout << (n - 2) * k + sum;
}