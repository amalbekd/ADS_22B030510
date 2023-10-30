#include <iostream>
#include <string>
using namespace std;

int partition(char arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i= (low - 1);
  
    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
  
void quick_sort(char arr[], int low, int high)
{
    if (low < high) {

        int pi = partition(arr, low, high);
  

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
  

int main() {
    int n; 
    cin >> n;

    char a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    char target; cin >> target;

    quick_sort(a, 0, n - 1);
    int cnt = 0;
    
    for (int i = 0; i < n; i++){
        if (a[i] > target) {
            cout << a[i];
            cnt++;
            return 0;
        }
    }
    if (cnt == 0) {
        cout << a[0];
    }
}