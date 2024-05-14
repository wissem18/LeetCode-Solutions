class Solution {
public:
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
int n, m;

int dp(int x, int y, vector<vector<int>> &grid) {
    if (x < 0 || x == n || y < 0 || y == m || !grid[x][y])
        return 0;


    int ans = 0;
    int val=grid[x][y];
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        grid[x][y] = 0;
        ans = max(ans, dp(nx, ny, grid) +val);
        grid[x][y]=val;
    }
    return ans;
}

int getMaximumGold(vector<vector<int>> &grid) {
    n = grid.size();
    m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j]) {
                ans = max(ans, dp(i, j, grid));
            }
        }
    }
    return ans;
}
};