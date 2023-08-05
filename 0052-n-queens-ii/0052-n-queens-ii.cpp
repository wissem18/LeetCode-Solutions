class Solution {
public:
vector<bool> col, diag1, diag2;

int rec(int i, int &n) {
    if (i == n) {
        return 1;
    }
    int res=0;
    for (int j = 0; j < n; ++j) {
        if (!col[j] && !diag1[j - i + n - 1] && !diag2[i + j]) {
            col[j] = true;
            diag1[j - i + n - 1] = true;
            diag2[i + j] = true;
            res+=rec(i + 1, n);
            col[j] = false;
            diag1[j - i + n - 1] = false;
            diag2[i + j] = false;
        }
    }
    return res;
}

int totalNQueens(int n) {
    col.assign(n, false);
    diag1.assign(2 * n, false);
    diag2.assign(2 * n, false);
    return rec(0, n);
}
};