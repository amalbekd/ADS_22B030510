#include <iostream>
#include <vector>
#include <map>
 
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    map<int, int> frequency;
    for (int i = 0; i < n; ++i) {
        frequency[numbers[i]]++;
    }

    int maxFrequency = 0;
    int mode = -1;
    map<int,int>::iterator it;

    for(it = frequency.begin(); it != frequency.end(); it++){
        if(it->second > maxFrequency){
            maxFrequency = it->second;
            mode = it->first;
        }
    }

    cout << mode;

    return 0;
}