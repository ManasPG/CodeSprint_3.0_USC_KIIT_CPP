#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> mat(M, vector<int>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> ans;

    for (int d = 0; d <= M + N - 2; d++) {
        vector<int> diag;

        int row = min(d, M - 1);
        int col = d - row;

        while (row >= 0 && col < N) {
            diag.push_back(mat[row][col]);
            row--;
            col++;
        }

        if (d % 2 == 1)
            reverse(diag.begin(), diag.end());

        for (int x : diag)
            ans.push_back(x);
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";

    return 0;
}