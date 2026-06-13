#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int x;
    cin >> x;

    int low = 0;
    int high = n * m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;
        if (mat[row][col] == x)
        {
            cout << "FOUND";
            return 0;
        }

        else if (mat[row][col] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "NOT FOUND";
    return 0;
}