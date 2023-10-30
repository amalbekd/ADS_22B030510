#include <iostream>

using namespace std;

void quick_sort(string &str, int left, int right) {
          int i = left, j = right;
          int mid = str[(left + right) / 2];

          while (i <= j) {
                while (str[i] < mid)
                      i++;
                while (str[j] > mid)
                      j--;
                if (i <= j) {
                      swap(str[i], str[j]);
                      i++; j--;
                }
          }

          if (left < j)
                quick_sort(str, left, j);
          if (i < right)
                quick_sort(str, i, right);
    }

int main(){

    string str;
    cin >> str;

    quick_sort(str, 0, str.size()-1);
    cout << str;
}