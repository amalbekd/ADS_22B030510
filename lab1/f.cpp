#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num){
    if(num < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int n_th_prime(int n){
    int cnt = 0;
    int num = 2;
    while(cnt < n){
        if(isPrime(num)){
            cnt++;
        }
        num++;
    }
    return num - 1;
}

int main(){

    int n;
    cin >> n;

    cout << n_th_prime(n);

    return 0;
}