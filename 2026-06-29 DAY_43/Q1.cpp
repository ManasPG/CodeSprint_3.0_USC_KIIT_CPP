#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Edge {
    int to;
    int travel;
    int expiry;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<Edge> > graph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, t, e;
        cin >> u >> v >> t >> e;
        graph[u].push_back({v, t, e});
    }

    const long long INF = 4e18;
    vector<long long> dist(N + 1, INF);

    priority_queue<
        pair<long long, long long>,
        vector<pair<long long, long long> >,
        greater<pair<long long, long long> >
    > pq;

    dist[1] = 0;
    pq.push(make_pair(0LL, 1LL));

    while (!pq.empty()) {

        pair<long long, long long> cur = pq.top();
        pq.pop();

        long long d = cur.first;
        long long u = cur.second;

        if (d != dist[u])
            continue;

        for (int i = 0; i < (int)graph[u].size(); i++) {

            Edge edge = graph[u][i];

            // Can use the road only if we reach u before expiry
            if (dist[u] >= edge.expiry)
                continue;

            long long nd = dist[u] + edge.travel;

            if (nd < dist[edge.to]) {
                dist[edge.to] = nd;
                pq.push(make_pair(nd, edge.to));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF)
            cout << -1;
        else
            cout << dist[i];

        if (i != N)
            cout << " ";
    }

    cout << "\n";

    return 0;
}