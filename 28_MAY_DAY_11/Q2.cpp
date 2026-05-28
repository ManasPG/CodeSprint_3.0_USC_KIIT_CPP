#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<string, int>> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i].first >> nums[i].second;
    }

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j].second > nums[j + 1].second)
            {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }

    for (pair<string, int> i : nums)
    {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}