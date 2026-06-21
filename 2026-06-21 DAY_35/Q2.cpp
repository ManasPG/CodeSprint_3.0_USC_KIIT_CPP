#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int ans = 0, low = 0, high = n - 1;

    while (low < high)
    {
        long long sum = 1LL * nums[low] + nums[high];
        if (sum == x)
        {
            ans++;
            long long leftval = nums[low];
            long long rightval = nums[high];

            while (low < high && leftval == nums[low])
                low++;
            while (low < high && rightval == nums[high])
                high--;
        }
        else if (sum < x)
            low++;
        else
            high--;
    }

    cout << ans;
    return 0;
}