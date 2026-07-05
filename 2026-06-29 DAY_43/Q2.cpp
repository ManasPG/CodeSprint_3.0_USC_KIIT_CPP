#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Edge{
    int u, v, w;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    vector<vector<int> > rev(N + 1);

    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        rev[v].push_back(u);
    }

    // Find all nodes that can reach N
    vector<int> canReachN(N + 1, 0);
    queue<int> q;
    q.push(N);
    canReachN[N] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < (int)rev[u].size(); i++){
            int v = rev[u][i];
            if(!canReachN[v]){
                canReachN[v] = 1;
                q.push(v);
            }
        }
    }

    const long long NEG = -4e18;

    vector<long long> dist(N + 1, NEG);
    dist[1] = 0;

    // Bellman-Ford
    for(int i = 1; i <= N - 1; i++){
        bool changed = false;

        for(int j = 0; j < M; j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] == NEG) continue;

            if(dist[u] + w > dist[v]){
                dist[v] = dist[u] + w;
                changed = true;
            }
        }

        if(!changed) break;
    }

    // Check for positive cycle affecting destination
    for(int j = 0; j < M; j++){
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] == NEG) continue;

        if(dist[u] + w > dist[v] && canReachN[v]){
            cout << "INFINITE PROFIT\n";
            return 0;
        }
    }

    if(dist[N] == NEG)
        cout << "UNREACHABLE\n";
    else
        cout << dist[N] << "\n";

    return 0;
}