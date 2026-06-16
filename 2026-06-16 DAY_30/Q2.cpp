#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    stack<int> st;
    int ans = 0;

    int n = s.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            int digit = s[i] - '0';
            st.push(digit);
        }
        else
        {
            char c = s[i];
            if (c == '+')
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                ans = a + b;
                st.push(ans);
            }
            else if (c == '-')
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                ans = a - b;
                st.push(ans);
            }
            else if (c == '/')
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                ans = a / b;
                st.push(ans);
            }
            else
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                ans = a * b;
                st.push(ans);
            }
        }
    }
    cout << st.top();
    return 0;
}