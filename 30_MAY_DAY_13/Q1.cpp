#include <bits/stdc++.h>
using namespace std;

int is(vector<int> &nums, int index)
{
    int element = nums[index];
    int i = index - 1;
    while (i >= 0 && nums[i] > element)
    {
        nums[i + 1] = nums[i];
        i--;
    }

    nums[i + 1] = element;
    return index - i - 1;
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

    if (n == 1)
    {
        cout << nums[0];
        return 0;
    }

    int shifts = 0;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            shifts += is(nums, i);
        }
    }

    for (int i : nums)
    {
        cout << i << " ";
    }

    cout << "\n"
         << shifts;

    return 0;
}
