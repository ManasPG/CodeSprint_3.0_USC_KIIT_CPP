#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c = 'A' + i;
        for (int j = 0; j < n; j++)
        {
            if (j == i || j == n - i - 1)
            {
                cout << c << " ";
            }
            else
                cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}