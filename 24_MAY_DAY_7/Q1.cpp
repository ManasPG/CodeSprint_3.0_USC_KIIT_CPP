#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() != s2.size())
    {
        cout << "NO";
        return 0;
    }

    vector<int> freq(26, 0);

    for (char c : s1)
        freq[c - 'a']++;
    for (char c : s2)
        freq[c - 'a']--;

    for (int i : freq)
    {
        if (i != 0)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}