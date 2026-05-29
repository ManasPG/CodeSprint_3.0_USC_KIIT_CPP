#include <bits/stdc++.h>
using namespace std;

pair<int, int> expandAroundCenter(const string &s, int left, int right)
{
    int n = s.length();
    while (left >= 0 && right < n && s[left] == s[right])
    {
        left--;
        right++;
    }

    int start_idx = left + 1;
    int length = (right - 1) - (left + 1) + 1;
    return {start_idx, length};
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    if (n < 2)
    {
        cout << s;
        return 0;
    }
    int max_len = 0;
    int start_pos = 0;

    for (int i = 0; i < n; i++)
    {
        auto p1 = expandAroundCenter(s, i, i);
        if (p1.second > max_len)
        {
            max_len = p1.second;
            start_pos = p1.first;
        }
        auto p2 = expandAroundCenter(s, i, i + 1);
        if (p2.second > max_len)
        {
            max_len = p2.second;
            start_pos = p2.first;
        }
    }

    cout << s.substr(start_pos, max_len) << "\n";
    return 0;
}