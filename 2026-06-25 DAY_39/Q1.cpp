#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> board;
vector<vector<string>> solutions;
vector<int> col, diag1, diag2;

void solve(int row) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++) {
        if (col[c] || diag1[row - c + n - 1] || diag2[row + c]) continue;

        board[row][c] = 'Q';
        col[c] = diag1[row - c + n - 1] = diag2[row + c] = 1;

        solve(row + 1);

        board[row][c] = '.';
        col[c] = diag1[row - c + n - 1] = diag2[row + c] = 0;
    }
}

int main() {
    cin >> n;

    board.assign(n, string(n, '.'));
    col.assign(n, 0);
    diag1.assign(2 * n - 1, 0);
    diag2.assign(2 * n - 1, 0);

    solve(0);

    if (solutions.empty()) {
        cout << -1;
        return 0;
    }

    for (size_t k = 0; k < solutions.size(); k++) {
        for (int i = 0; i < n; i++) {
            cout << solutions[k][i] << '\n';
        }
        if (k + 1 < solutions.size()) cout << '\n';
    }

    return 0;
}