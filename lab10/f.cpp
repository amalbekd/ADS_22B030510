#include <bits/stdc++.h>

using namespace std;

void dfs(int ver, vector<bool>& vis, const vector<vector<int>>& a) {
    vis[ver] = true;
    for (int neighbor : a[ver]) {
        if (!vis[neighbor]) {
            dfs(neighbor, vis, a);
        }
    }
}

bool areInSameComponent(int s, int f, const vector<vector<int>>& a) {
    int n = a.size();
    vector<bool> vis(n, false);

    dfs(s - 1, vis, a);

    return vis[f - 1];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyList(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adjacencyList[x - 1].push_back(y - 1);
        adjacencyList[y - 1].push_back(x - 1);
    }

    int s, f;
    cin >> s >> f;

    string result = areInSameComponent(s, f, adjacencyList) ? "YES" : "NO";
    
    cout << result << endl;

    return 0;
}