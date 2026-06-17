#include <bits/stdc++.h>
using namespace std;
int main()
{
    int Q;
    cin >> Q;
    stack<int> s1, s2;

    while (Q--)
    {
        string op;
        cin >> op;
        if (op == "ADD")
        {
            int x;
            cin >> x;
            s1.push(x);
        }
        else if (op == "NEXT")
        {
            if (s2.empty())
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            if (s2.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << s2.top() << "\n";
                s2.pop();
            }
        }
    }
    return 0;
}