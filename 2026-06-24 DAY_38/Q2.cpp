#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    unordered_set<int> hash;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        hash.insert(nums[i]);
    }

    int len = 0;

    for (int i = 0; i < n; i++)
    {
        if (hash.find(nums[i] - 1) == hash.end())
        {
            int cal = 1;
            int el = nums[i] + 1;
            while (hash.find(el) != hash.end())
            {
                cal++;
                el++;
            }
            len = max(len, cal);
        }
    }
    cout << len;
    return 0;
}