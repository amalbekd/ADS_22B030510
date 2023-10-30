#include <bits/stdc++.h>

using namespace std;

int main(){

    deque<int> deq1(5), deq2(5);

    for(int i=0; i<5; i++){
        cin >> deq1[i];
    }
    for(int i=0; i<5; i++){
        cin >> deq2[i];
    }
    int cnt=0;
    
    while(!deq1.empty() && !deq2.empty() && cnt<1000000){
        cnt++;
        int Boris = deq1.front();
        int Nursik = deq2.front();
        deq1.pop_front();
        deq2.pop_front();
        if(Boris==0 && Nursik == 9){
            deq1.push_back(Boris);
            deq1.push_back(Nursik);
        }
        else if(Boris==9 && Nursik == 0){
            deq2.push_back(Boris);
            deq2.push_back(Nursik);
        }
        else if(Boris>Nursik){
            deq1.push_back(Boris);
            deq1.push_back(Nursik);
        }
        else {
            deq2.push_back(Boris);
            deq2.push_back(Nursik);
        }
    }

    if(deq1.empty()){
        cout << "Nursik " << cnt;
    }
    else if(deq2.empty()){
        cout << "Boris " << cnt;

    } else {
        cout << "blin nichya" << endl;
    }
}