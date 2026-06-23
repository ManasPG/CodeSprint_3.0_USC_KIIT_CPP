#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_map<long long, long long> mp;
    mp[0] = 1;
    long long prefix = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        prefix += nums[i];
        if (mp.count(prefix - k))
            ans += mp[prefix - k];

        mp[prefix]++;
    }

    cout << ans;

    return 0;
}