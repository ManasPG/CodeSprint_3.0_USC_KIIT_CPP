#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<long long> st;
    long long num = 0;
    char op = '+';

    for (int i = 0; i <= s.size(); i++)
    {
        if (i < s.size() && isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }
        else
        {
            if (op == '+')
                st.push(num);
            else if (op == '-')
                st.push(-num);
            else if (op == '*')
            {
                long long top = st.top();
                st.pop();
                st.push(top * num);
            }
            else if (op == '/')
            {
                long long top = st.top();
                st.pop();
                st.push(top / num);
            }

            if (i < s.size())
                op = s[i];

            num = 0;
        }
    }

    long long ans = 0;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    cout << ans;
    return 0;
}