class Solution {
public:
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
vector<vector<int>> vis;
bool valid = true;

void dfs(int x, int y, vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    vis[x][y] = 1;
    if (!grid1[x][y])
        valid = false;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < grid2.size() && ny >= 0 && ny < grid2[0].size() && !vis[nx][ny] && grid2[nx][ny])
            dfs(nx, ny, grid1, grid2);
    }
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    int n = grid1.size();
    int m = grid1[0].size();
    vis.assign(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid2[i][j] && !vis[i][j]) {
                valid = true;
                dfs(i, j, grid1, grid2);
                if (valid)
                    ans++;
            }
        }
    }
    return ans;
}
};