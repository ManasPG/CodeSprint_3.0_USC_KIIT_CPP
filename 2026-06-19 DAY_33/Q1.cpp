#include <bits/stdc++.h>
using namespace std;

class cmp
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
};

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int id;
        int pr;
        cin >> id >> pr;
        pq.push({id, pr});
    }
    while (!pq.empty())
    {
        cout << pq.top().first << "\n";
        pq.pop();
    }
    return 0;
}