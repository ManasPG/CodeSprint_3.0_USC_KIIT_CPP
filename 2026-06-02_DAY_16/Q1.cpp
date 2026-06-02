#include <bits/stdc++.h>
using namespace std;
int main()
{
    string jewels, stones;
    cin >> jewels >> stones;

    unordered_set<char> hash;

    for (char c : jewels)
    {
        hash.insert(c);
    }

    int count = 0;
    for (char c : stones)
    {
        if (hash.find(c) != hash.end())
        {
            count++;
        }
    }

    cout << count;
    return 0;
}