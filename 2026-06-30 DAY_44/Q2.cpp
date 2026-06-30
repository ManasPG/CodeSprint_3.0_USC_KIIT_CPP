#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int FULL = 1 << N;

    vector<vector<bool>> dp(FULL, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        dp[1 << i][i] = true;
    }

    for (int mask = 1; mask < FULL; mask++)
    {
        for (int u = 0; u < N; u++)
        {
            if (!dp[mask][u])
                continue;

            for (int v : adj[u])
            {
                if (!(mask & (1 << v)))
                {
                    dp[mask | (1 << v)][v] = true;
                }
            }
        }
    }

    int all = FULL - 1;

    for (int i = 0; i < N; i++)
    {
        if (dp[all][i])
        {
            cout << "MISSION POSSIBLE";
            return 0;
        }
    }

    cout << "MISSION FAILED";
    return 0;
}