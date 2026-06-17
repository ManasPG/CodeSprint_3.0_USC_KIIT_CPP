#include <bits/stdc++.h>
using namespace std;
int main()
{
    int Q;
    cin >> Q;

    stack<int> st, mn;

    while (Q--)
    {
        string op;
        cin >> op;

        if (op == "PUSH")
        {
            int x;
            cin >> x;

            st.push(x);

            if (mn.empty())
                mn.push(x);
            else
                mn.push(min(x, mn.top()));
        }
        else if (op == "POP")
        {
            if (!st.empty())
            {
                st.pop();
                mn.pop();
            }
        }
        else if (op == "MIN")
        {
            if (st.empty())
                cout << -1 << "\n";
            else
                cout << mn.top() << "\n";
        }
    }
    return 0;
}