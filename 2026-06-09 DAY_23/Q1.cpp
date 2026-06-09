#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int LOG = log2(n) + 1;

    vector<vector<long long>> stMin(n, vector<long long>(LOG));
    vector<vector<long long>> stMax(n, vector<long long>(LOG));

    for (int i = 0; i < n; i++)
    {
        stMin[i][0] = a[i];
        stMax[i][0] = a[i];
    }

    for (int j = 1; j < LOG; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);

            stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
        }
    }

    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int len = r - l + 1;
        int k = lg[len];

        long long mn = min(stMin[l][k], stMin[r - (1 << k) + 1][k]);
        long long mx = max(stMax[l][k], stMax[r - (1 << k) + 1][k]);

        cout << mx - mn << "\n";
    }
}