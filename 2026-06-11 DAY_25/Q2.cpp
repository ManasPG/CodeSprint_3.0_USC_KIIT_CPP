#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;

    unordered_map<char, int> need;
    for (char c : t)
    {
        need[c]++;
    }

    int required = need.size();
    int formed = 0;

    unordered_map<char, int> window;

    int l = 0;
    int minLen = INT_MAX;
    int start = -1;

    for (int r = 0; r < s.size(); r++)
    {
        char c = s[r];
        window[c]++;

        if (need.count(c) && window[c] == need[c])
        {
            formed++;
        }

        while (formed == required)
        {
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                start = l;
            }

            char left = s[l];

            window[left]--;

            if (need.count(left) && window[left] < need[left])
                formed--;

            l++;
        }
    }

    if (start == -1)
        cout << -1;
    else
        cout << s.substr(start, minLen);

    return 0;
}