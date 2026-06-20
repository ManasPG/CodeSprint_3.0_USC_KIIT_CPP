#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int cost, energy;
        cin >> cost >> energy;
        for (int j = cost; j <= x; j++)
        {
            dp[j] = max(dp[j], dp[j - cost] + energy);
        }
    }

    cout << dp[x];
    return 0;
}