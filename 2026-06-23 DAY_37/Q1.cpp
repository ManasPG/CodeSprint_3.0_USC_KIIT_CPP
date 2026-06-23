#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        pq.push(el);
    }

    vector<int> el;
    for (int i = 0; i < k; i++)
    {
        el.push_back(pq.top());
        pq.pop();
    }

    for (int i = k - 1; i >= 0; i--)
    {
        cout << el[i] << " ";
    }
    return 0;
}