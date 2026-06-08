#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &vis, string path, vector<string> &ans, int n)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }

    vis[i][j] = 1;

    if (i + 1 < n && mat[i + 1][j] == 1 && !vis[i + 1][j])
        solve(i + 1, j, mat, vis, path + 'D', ans, n);
    if (j - 1 >= 0 && mat[i][j - 1] == 1 && !vis[i][j - 1])
    {
        solve(i, j - 1, mat, vis, path + 'L', ans, n);
    }
    if (j + 1 < n && mat[i][j + 1] == 1 && !vis[i][j + 1])
    {
        solve(i, j + 1, mat, vis, path + 'R', ans, n);
    }
    if (i - 1 >= 0 && mat[i - 1][j] == 1 && !vis[i - 1][j])
    {
        solve(i - 1, j, mat, vis, path + 'U', ans, n);
    }

    vis[i][j] = 0;
}

void pvp(vector<vector<int>> &mat, int n)
{
    vector<string> ans;

    if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
    {
        cout << -1;
        return;
    }

    vector<vector<int>> vis(n, vector<int>(n, 0));

    solve(0, 0, mat, vis, "", ans, n);

    if (ans.empty())
    {
        cout << -1;
        return;
    }

    sort(ans.begin(), ans.end());

    for (auto &s : ans)
    {
        cout << s << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    pvp(mat, n);
    return 0;
}