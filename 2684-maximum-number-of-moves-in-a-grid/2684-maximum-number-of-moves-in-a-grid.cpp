class Solution {
public:
int n, m;
vector<vector<int>> mem;

int dp(int i, int j, vector<vector<int>> &grid) {
    if (mem[i][j] != -1)
        return mem[i][j];

    int ans = 0;
    for (int k = -1; k <= 1; ++k) {
        int ni = i + k;
        int nj = j + 1;
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] > grid[i][j])
            ans = max(ans, 1 + dp(ni, nj, grid));
    }
    return mem[i][j] = ans;
}

int maxMoves(vector<vector<int>> &grid) {
    n = grid.size();
    m = grid[0].size();
    mem.assign(n, vector<int>(m, -1));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp(i, 0, grid));
    }
    return ans;
}
};