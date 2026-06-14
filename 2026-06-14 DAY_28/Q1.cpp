#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);

    stack<char> st;

    for (char c : s)
    {
        if (c == ')' || c == ']' || c == '}' || c == '>')
        {
            if (st.empty())
            {
                cout << "INVALID";
                return 0;
            }

            if (c == ')' && st.top() == '(')
            {
                st.pop();
            }
            else if (c == '}' && st.top() == '{')
            {
                st.pop();
            }
            else if (c == ']' && st.top() == '[')
            {
                st.pop();
            }
            else if (c == '>' && st.top() == '<')
            {
                st.pop();
            }
            else
            {
                cout << "INVALID";
                return 0;
            }
        }
        else
            st.push(c);
    }
    if (st.empty())
        cout << "VALID";
    else
        cout << "INVALID";
    return 0;
}