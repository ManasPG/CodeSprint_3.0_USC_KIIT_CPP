#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> scores(n);
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    sort(scores.begin(), scores.end(), greater<int>());

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int el;
        cin >> el;

        int low = 0;
        int high = n - 1;
        bool found = false;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (scores[mid] == el)
            {
                cout << "Rank " << mid + 1 << "\n";
                found = true;
                break;
            }

            else if (scores[mid] > el)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if (!found)
            cout << "No Rank\n";
    }

    return 0;
}