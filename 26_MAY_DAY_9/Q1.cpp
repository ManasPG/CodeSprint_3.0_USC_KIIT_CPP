#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int left = 0;
    int right = n - 1;
    int indx = n - 1;

    while (left <= right)
    {
        int l = nums[left] * nums[left];
        int r = nums[right] * nums[right];

        if (l > r)
        {
            ans[indx] = l;
            left++;
        }
        else
        {
            ans[indx] = r;
            right--;
        }
        indx--;
    }

    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}