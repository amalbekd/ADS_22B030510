#include <bits/stdc++.h>

using namespace std;

int main()
{

int a, b;
cin >> a >> b;
deque<int> v;
while(b != a){
    v.push_front(b);
    if(b % 2 != 0 || b < a){
        b += 1;
    } else {
    b /= 2;
    }
}
cout << v.size() << endl;
for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
}




return 0;
}