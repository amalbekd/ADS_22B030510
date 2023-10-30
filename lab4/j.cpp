#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void build_balanced_bst(vector<int>& arr, int l, int r) {
    if (l > r) return;

    int mid = l + (r - l) / 2;
    cout << arr[mid] << " ";

    build_balanced_bst(arr, l, mid - 1);
    build_balanced_bst(arr, mid + 1, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(pow(2, n) - 1);
    for (int i = 0; i < pow(2, n) - 1; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    build_balanced_bst(arr, 0, pow(2, n) - 2);
}