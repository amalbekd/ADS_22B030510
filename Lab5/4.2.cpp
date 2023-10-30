#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> densities(n);
    for (int i = 0; i < n; i++) {
        cin >> densities[i];
    }

    if (m == 0) {
        cout << "0" << endl;
        return 0;
    }

    priority_queue<int, vector<int>, greater<int>> pq(densities.begin(), densities.end());

    int operations = 0;

    while (pq.top() < m) {
        if (pq.size() < 2) {
            cout << "-1" << endl;
            return 0;
        }

        int least_density = pq.top();
        pq.pop();
        int second_least_density = pq.top();
        pq.pop();

        int new_density = least_density + 2 * second_least_density;
        pq.push(new_density);
        operations++;
    }

    cout << operations << endl;

    return 0;
}
