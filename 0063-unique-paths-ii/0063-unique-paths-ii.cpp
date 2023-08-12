class Solution {
public:
 int mem[105][105];
int n, m;

int dp(int i, int j, vector<vector<int>> &obstacleGrid) {
    if (i == n - 1 && j == m - 1) {
        return !obstacleGrid[i][j];
    }
    if (mem[i][j] != -1)
        return mem[i][j];
    int ans = 0;
    if (i + 1 < n && !obstacleGrid[i + 1][j])
        ans += dp(i + 1, j, obstacleGrid);
    if (j + 1 < m && !obstacleGrid[i][j + 1])
        ans += dp(i, j + 1, obstacleGrid);
    return mem[i][j] = ans;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    n = obstacleGrid.size();
    m = obstacleGrid[0].size();
    if(obstacleGrid[0][0])
        return 0;
    memset(mem, -1, sizeof mem);
    return dp(0,0,obstacleGrid);
}
};