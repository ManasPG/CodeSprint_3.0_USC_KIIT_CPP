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
  int target;
  cin >> target;
  sort(nums.begin(), nums.end());
  bool found = false;
  for (int i = 0; i < n - 2; i++)
  {
    int left = i + 1;
    int right = n - 1;
    while (left < right)
    {
      int sum = nums[i] + nums[left] + nums[right];
      if (sum == target)
      {
        found = true;
        break;
      }
      else if (sum < target)
        left++;
      else
        right--;
    }
    if (found)
      break;
  }
  if (found)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}