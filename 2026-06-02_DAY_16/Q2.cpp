#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K, X;
    cin >> N >> K >> X;

    if (K > N)
    {
        cout << "NO";
        return 0;
    }

    vector<int> nums(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    int i = 0;
    long long sum = 0;
    for (int j = 0; j < N; j++)
    {
        if (nums[j] == 0)
        {
            sum = 0;
            i = j + 1;
            continue;
        }
        sum += nums[j];
        if (j - i + 1 == K)
        {
            if (sum >= X)
            {
                cout << "YES";
                return 0;
            }
            else
            {
                sum -= nums[i];
                i++;
            }
        }
    }
    cout << "NO";
    return 0;
}