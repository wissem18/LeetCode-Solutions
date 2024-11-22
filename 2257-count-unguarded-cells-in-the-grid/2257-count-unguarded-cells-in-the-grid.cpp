class Solution {
public:
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
vector<vector<int>> grid;

int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
    grid.resize(m, vector<int>(n, 0));
    for (auto g: guards) {
        grid[g[0]][g[1]] = 2;
    }
    for (auto w: walls) {
        grid[w[0]][w[1]] = 3;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 2) {
                for (int k = 0; k < 4; ++k) {
                    int curi = i, curj = j;
                    while (curi + dx[k] >= 0 && curj + dy[k] >= 0 && curi + dx[k] < m && curj + dy[k] < n &&
                           grid[curi + dx[k]][curj + dy[k]] < 2) {
                        grid[curi + dx[k]][curj + dy[k]] = 1;
                        curi = curi + dx[k];
                        curj = curj + dy[k];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!grid[i][j])
                ans++;
        }
    }
    return ans;
}
};