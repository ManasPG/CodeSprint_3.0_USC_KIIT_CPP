#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, w;
    cin >> n >> w;

    vector<int> weights(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    int l = 0;
    int sum = 0;
    int maxi = 0;

    for (int r = 0; r < n; r++)
    {
        sum += weights[r];
        if (sum > w)
        {
            while (sum > w)
            {
                sum -= weights[l++];
            }
        }
        maxi = max(r - l + 1, maxi);
    }

    cout << maxi;
    return 0;
}