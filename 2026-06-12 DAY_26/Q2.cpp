#include <bits/stdc++.h>
using namespace std;

long long totalMoves = 0;

void hanoi(int n, char source, char auxillary, char destination)
{
    if (n == 1)
    {
        cout << "Move plate 1 from " << source << " to " << destination << "\n";
        totalMoves++;
        return;
    }

    hanoi(n - 1, source, destination, auxillary);

    cout << "Move plate " << n << " from " << source << " to " << destination << "\n";
    totalMoves++;
    hanoi(n - 1, auxillary, source, destination);
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    cout << "Total Moves = " << totalMoves << "\n";
    return 0;
}