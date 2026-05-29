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

  sort(nums.begin(), nums.end());

  int l = 0;
  int r = n - 1;

  pair<int, int> ans;
  int min_sum = INT_MAX;

  while (l < r)
  {
    int curr_sum = nums[l] + nums[r];
    if (abs(curr_sum) < min_sum)
    {
      min_sum = abs(curr_sum);
      ans = {nums[l], nums[r]};
    }

    if (curr_sum < 0)
      l++;
    else if (curr_sum > 0)
      r--;
    else
      break;
  }

  cout << ans.first << " " << ans.second;
}