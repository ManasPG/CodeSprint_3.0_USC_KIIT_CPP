#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int low = 1;
    int high = n - 2;
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            ans = nums[mid];
            break;
        }
        else if (nums[mid] >= nums[mid - 1] && nums[mid] <= nums[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans;
}