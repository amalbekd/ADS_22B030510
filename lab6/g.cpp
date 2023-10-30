#include <iostream>
#include <map>
#include <vector>

using namespace std;

int partition(char arr[], int low, int high){
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
  
void quick_sort(char arr[], int low, int high){

    if (low < high) {

        int pi = partition(arr, low, high);
  

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main(){

    map<string,string> m;
    map<string, string>:: iterator it;

    int n; 
    cin >> n;
    
    for(int i = 0; i < n; i++){
        string newName; string oldName;
        cin >> newName; cin >> oldName;

        if (m.empty()) {
            m[newName] = oldName;
        }

        if(!m.empty()){
            for(it = m.begin(); it != m.end(); it++){
                if(newName == it->second){
                    m[it->first] = oldName;
                    m.erase(newName);
                    break;
                }
                else{
                    m[newName] = oldName;
                }
            }
        }
    }
    
    cout << m.size() << endl;
 
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}