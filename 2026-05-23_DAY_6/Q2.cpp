#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int p = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;

            if (i == j)
                p += x;
            if (i + j == n - 1)
                s += x;
        }
    }
    if (p == s)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}