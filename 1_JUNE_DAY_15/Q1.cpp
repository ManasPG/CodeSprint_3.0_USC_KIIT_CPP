#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a, string &b)
{
    int v1 = 0;
    int v2 = 0;

    for (char c : a)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            v1++;
    }

    for (char c : b)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            v2++;
    }

    if (v1 != v2)
        return v1 > v2;

    if (a.size() != b.size())
        return a.size() < b.size();

    return a < b;
}

int main()
{
    int n;
    cin >> n;
    vector<string> store(n);
    for (int i = 0; i < n; i++)
    {
        cin >> store[i];
    }

    if (n == 1)
    {
        cout << store[0];
        return 0;
    }

    sort(store.begin(), store.end(), cmp);

    for (string s : store)
    {
        cout << s << "\n";
    }
    return 0;
}