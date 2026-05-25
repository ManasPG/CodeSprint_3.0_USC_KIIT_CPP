#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        nums.push_back(el);
    }
    for (int i : nums)
    {
        int cnt = __builtin_popcount(i);
        if (cnt % 2 == 0)
            cout << "SAFE\n";
        else
            cout << "ANSWER\n";
    }
    return 0;
}