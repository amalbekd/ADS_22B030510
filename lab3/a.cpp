#include <iostream>

using namespace std;

int main(){

    int t;
    cin >> t;
    int a[t];

    for(int i = 0; i < t; i++){
        cin >> a[i];
    }

    int n, m;
    cin >> n >> m;
    int snake[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> snake[i][j];
        }
    }


    for(int l = 0; l < t; l++){
        bool cnt = 1;

        for(int i = n - 1; i != -1; i--){
            if(i % 2 == 0 and snake[i][0] < a[l]){
                continue;
            } else if(i % 2 == 1 and snake[i][m - 1] < a[l]){
                continue;
            }
            for(int j = 0; j < m; j++){
                if(a[l] == snake[i][j]){
                    cout << i << ' ' << j;
                    cnt = 0;
                }
            }
        }


        if(cnt) cout << -1;
        cout << endl;
    }

    return 0;
}