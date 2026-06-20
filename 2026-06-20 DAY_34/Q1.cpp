#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 2)
                q.push({i, j});
            else if (mat[i][j] == 1)
                fresh++;
        }
    }

    if (fresh == 0)
    {
        cout << 0;
        return 0;
    }

    int minutes = 0;

    vector<pair<int, int>> dir = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

    while (!q.empty())
    {
        int sz = q.size();
        bool infected = false;

        while (sz--)
        {
            auto [r, c] = q.front();
            q.pop();

            for (auto it : dir)
            {
                int nr = r + it.first;
                int nc = c + it.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1)
                {
                    mat[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                    infected = true;
                }
            }
        }
        if (infected)
            minutes++;
    }

    if (fresh > 0)
        cout << -1;
    else
        cout << minutes;

    return 0;
}