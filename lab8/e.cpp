#include <bits/stdc++.h>

using namespace std;

#define ll long long

string restoreString(int n, vector<ll>& hashes) {
    string result = "";
    for (int i = 0; i < n; i++) {
        ll hashValue = hashes[i];
        if (i > 0) {
            ll prevHash = hashes[i - 1];
            char ch = ((hashValue - prevHash) / (1LL << i)) + 'a';
            result += ch;
        } else {
            char ch = (hashValue / (1LL << i)) + 'a';
            result += ch;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<ll> hashes(n);

    for (int i = 0; i < n; i++) {
        cin >> hashes[i];
    }

    string result = restoreString(n, hashes);
    cout << result << endl;

    return 0;
}

