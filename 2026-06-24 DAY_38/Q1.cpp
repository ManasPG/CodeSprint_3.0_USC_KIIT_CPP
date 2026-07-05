#include <bits/stdc++.h>
using namespace std;

map<char, string> mp = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}};

vector<string> ans;

void solve(string &digits, int idx, string curr)
{
    if (idx == digits.size())
    {
        ans.push_back(curr);
        return;
    }

    for (char ch : mp[digits[idx]])
    {
        solve(digits, idx + 1, curr + ch);
    }
}
int main()
{
    string digits;
    cin >> digits;

    solve(digits, 0, "");

    for (string s : ans)
    {
        cout << s << " ";
    }

    return 0;
}