#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int prev = -1;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        if (el == prev)
        {
            cout << "INVALID " << i;
            return 0;
        }
        prev = el;
    }
    cout << "VALID";
    return 0;
}