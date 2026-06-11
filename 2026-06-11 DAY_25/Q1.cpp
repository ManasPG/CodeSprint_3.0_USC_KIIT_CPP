#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    int l = 0;
    int r = n - 1;
    int ans = 0;

    while (l < r)
    {
        ans = max(ans, min(heights[l], heights[r]) * (r - l));

        if (heights[l] < heights[r])
            l++;
        else
            r--;
    }

    cout << ans;
}