#include <bits/stdc++.h>
using namespace std;

int ss(vector<int> &nums)
{
    int swaps = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        pair<int, int> mn = {nums[i], i};

        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] < mn.first)
            {
                mn = {nums[j], j};
            }
        }
        if (mn.second != i)
        {
            swaps++;
            swap(nums[i], nums[mn.second]);
        }
    }
    return swaps;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int swaps = ss(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
        if (i == n - 1)
            cout << "\n";
    }
    cout << swaps;

    return 0;
}