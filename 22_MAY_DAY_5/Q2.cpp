#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    int X;
    cin >> N;
    cin >> X;
    int sum = 0;
    int index = -1;
    for (int i = 0; i < N; i++)
    {
        int el;
        cin >> el;
        sum += el;
        if (sum > X && index == -1)
            index = i;
    }
    cout << index;
    return 0;
}