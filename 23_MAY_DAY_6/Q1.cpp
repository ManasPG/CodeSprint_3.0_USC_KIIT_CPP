#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool up = false;
    bool lo = false;
    bool di = false;

    string s = "";
    cin >> s;

    for (char c : s)
    {
        if (isupper(c))
            up = true;
        if (islower(c))
            lo = true;
        if (isdigit(c))
            di = true;
    }

    if (up && lo && di)
        cout << "STRONG";
    else
        cout << "WEAK";
    return 0;
}