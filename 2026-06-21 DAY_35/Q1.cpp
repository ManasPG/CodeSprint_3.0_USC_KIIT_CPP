#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    vector<long long> pref(n);
    pref[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + nums[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int pos = lower_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
        long long smallerSum = (pos == 0 ? 0 : pref[pos - 1]);
        if (smallerSum >= k)
            ans++;
    }
    cout << ans << "\n";
    return 0;
}