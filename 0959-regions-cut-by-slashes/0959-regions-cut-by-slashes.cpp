class Solution {
public:
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
vector<vector<bool>> vis;

void dfs(int x, int y, vector<vector<int>> &grid) {
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 0 || vis[nx][ny])
            continue;
        dfs(nx, ny, grid);
    }
}

int regionsBySlashes(vector<string> &grid) {
    int n = grid.size();
    vector<vector<int>> newGrid(3 * n, vector<int>(3 * n, 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = 3 * i;
            int y = 3 * j;
            if (grid[i][j] == '/') {
                newGrid[x][y + 2] = newGrid[x + 1][y + 1] = newGrid[x + 2][y] = 0;
            } else if (grid[i][j] == '\\') {
                newGrid[x][y] = newGrid[x + 1][y + 1] = newGrid[x + 2][y + 2] = 0;
            }
        }
    }
    vis.assign(3*n, vector<bool>(3*n, false));
    int ans = 0;
    for (int i = 0; i < 3*n; ++i) {
        for (int j = 0; j <3*n ; ++j) {
            if (newGrid[i][j] == 1 && !vis[i][j]) {
                ans++;
                dfs(i, j, newGrid);
            }
        }
    }
    return ans;
}
};