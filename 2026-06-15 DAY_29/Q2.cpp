#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    stack<char> st;

    for (char c : s)
    {
        if (st.empty())
            st.push(c);
        else
        {
            if (st.top() == c)
                st.pop();
            else
                st.push(c);
        }
    }

    if (st.empty())
    {
        cout << "EMPTY";
        return 0;
    }

    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    cout << ans;
}