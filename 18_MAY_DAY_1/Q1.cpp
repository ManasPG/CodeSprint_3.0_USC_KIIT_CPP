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

    int ind = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[ind] != 0)
            ind++;

        else if (nums[i] != 0)
        {
            swap(nums[i], nums[ind]);
        }
    }

    for (int i : nums)
    {
        cout << i << " ";
    }
    return 0;
}