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

int countIslands(vector<vector<int>> &grid) {
    vis.assign(grid.size(), vector<bool>(grid[0].size(), false));
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1 && !vis[i][j]) {
                ans++;
                dfs(i, j, grid);
            }
            if (ans > 1)
                return ans;
        }
    }
    return ans;
}

int minDays(vector<vector<int>> &grid) {
    int cnt = countIslands(grid);
    if (cnt != 1)
        return 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
                if (countIslands(grid) != 1)
                    return 1;
                grid[i][j]=1;
            }
        }
    }
    return 2;
}
};