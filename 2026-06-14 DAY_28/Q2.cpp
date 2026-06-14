#include <bits/stdc++.h>
using namespace std;

void nextel(queue<int> &q)
{
    if (!q.empty())
    {
        cout << q.front() << "\n";
        q.pop();
    }
    else
        cout << -1 << "\n";
}

void reg(queue<int> &q, int num)
{
    q.push(num);
}
void withdraw(queue<int> &q)
{
    if (q.empty())
        cout << -1 << "\n";
    else
        q.pop();
}

int main()
{
    int n;
    cin >> n;

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        string com;
        cin >> com;

        if (com == "REGISTER")
        {
            int num;
            cin >> num;
            reg(q, num);
        }
        else if (com == "NEXT")
            nextel(q);
        else if (com == "WITHDRAW")
            withdraw(q);
        else
            cout << "INVALID INPUT";
    }

    return 0;
}