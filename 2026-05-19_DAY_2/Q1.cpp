#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    int sum = 0;
    vector<int> scores(n);
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
        sum += scores[i];
    }
    int avg = sum / n;

    for (int x : scores)
    {
        if (x > avg)
            cnt++;
    }

    cout << cnt;
    return 0;
}