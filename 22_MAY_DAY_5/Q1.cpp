#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<vector<int>> mat(n, vector<int>(n));
  vector<vector<char>> ans(n, vector<char>(n, 'S'));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> mat[i][j];
    }
  }

  vector<pair<int, int>> dir = {
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (mat[i][j] == 1)
      {
        ans[i][j] = 'O';

        for (auto it : dir)
        {
          int x = i + it.first;
          int y = j + it.second;

          if (x >= 0 && x < n &&
              y >= 0 && y < n &&
              mat[x][y] == 0 &&
              ans[x][y] != 'O')
          {
            ans[x][y] = 'X';
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}