#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    int el = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        el ^= nums[i];
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == el)
        {
            cout << el << " " << i + 1;
            break;
        }
    }

    return 0;
}