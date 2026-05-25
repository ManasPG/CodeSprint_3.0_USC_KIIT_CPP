#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int op = 0;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        op ^= el;
    }

    if (op == 0)
        cout << "BALANCED";
    else
        cout << "UNBALANCED";
    return 0;
}