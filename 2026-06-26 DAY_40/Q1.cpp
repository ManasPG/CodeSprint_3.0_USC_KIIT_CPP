#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> treasure(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> treasure[i];
    }

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int,int>> q; // {node, level}
    vector<bool> visited(N + 1, false);

    q.push(make_pair(1, 0));
    visited[1] = true;

    long long ans = 0;

    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();

        int node = cur.first;
        int level = cur.second;

        if (level % 2 == 0) {
            ans += treasure[node];
        }

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                visited[nei] = true;
                q.push(make_pair(nei, level + 1));
            }
        }
    }

    cout << ans << "\n";
    return 0;
}