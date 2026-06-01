#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int maxi = INT_MIN;
    int secmaxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > maxi)
        {
            secmaxi = maxi;
            maxi = x;
        }
        else if (x > secmaxi && x < maxi)
        {
            secmaxi = x;
        }
    }

    if (secmaxi == INT_MIN)
    {
        cout << -1;
        return 0;
    }

    cout << secmaxi;

    return 0;
}