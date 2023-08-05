class Solution {
public:
vector<vector<string>> ans;
vector<bool> col, diag1, diag2;

void rec(int i, int n, vector<string> cur) {
    if (i == n) {
        ans.push_back(cur);
        return;
    }
    for (int j = 0; j < n; ++j) {
        if (!col[j] && !diag1[j - i + n - 1] && !diag2[i + j]) {
            cur[i][j] = 'Q';
            col[j] = true;
            diag1[j - i + n - 1] = true;
            diag2[i + j] = true;
            rec(i + 1, n, cur);
            cur[i][j] = '.';
            col[j] = false;
            diag1[j - i + n - 1] = false;
            diag2[i + j] = false;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    col.assign(n, false);
    diag1.assign(2 * n, false);
    diag2.assign(2 * n, false);
    vector<string> cur(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cur[i].push_back('.');
        }
    }
    rec(0, n, cur);
    return ans;
}
};