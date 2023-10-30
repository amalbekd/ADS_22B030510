#include <iostream>

using namespace std;

int main(){

    int n, k = 0;
    cin >> n;
    if(n == 1){
        k++;
    }
    else{
        for(int i = 2; i < n; i++){
            if(n % i == 0){
                k++;
            }
        }
    }

    if(k == 0){
        cout << "YES";
    } else { 
        cout << "NO"; 
    }

    return 0;
}