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

    int l = 0, r = n - 1;

    int score = INT_MIN;

    while (l < r)
    {
        int dist = r - l;
        int s = min(nums[l], nums[r]) * dist;
        score = max(s, score);

        if (nums[l] <= nums[r])
        {
            l++;
        }
        else
            r--;
    }
    cout << score;
    return 0;
}