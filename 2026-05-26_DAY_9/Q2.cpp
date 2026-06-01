#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 1)
    {
        cout << arr[0];
        return 0;
    }

    string ans = "";
    for (int i = 0; i < arr[0].size(); i++)
    {
        char ch = arr[0][i];
        bool match = true;
        for (int j = 1; j < n; j++)
        {
            if (i >= arr[j].size() || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match)
            ans += ch;
        else
            break;
    }
    cout << ans;

    return 0;
}