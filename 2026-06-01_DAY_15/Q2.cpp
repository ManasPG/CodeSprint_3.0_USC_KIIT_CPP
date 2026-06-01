#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int maxi = INT_MIN;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        maxi = max(maxi, nums[i++] + nums[j--]);
    }

    cout << maxi;
    return 0;
}