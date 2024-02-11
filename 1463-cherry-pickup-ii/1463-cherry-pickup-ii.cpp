class Solution {
public:
int n, m;
int mem[70][70][70];
vector<int> dr1 = {0, 0, 0, 1, 1, 1, -1, -1, -1};
vector<int> dr2 = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int dp(int i, int j1, int j2, vector<vector<int>> &grid) {
    if (i == n)
        return 0;
    if (mem[i][j1][j2] != -1)
        return mem[i][j1][j2];

    int ans = 0;
    for (int j = 0; j < 9; ++j) {
        int nj1 = j1 + dr1[j], nj2 = j2 + dr2[j];
        if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
            ans = max(ans, dp(i + 1, nj1, nj2, grid));
        }   
    }
    return mem[i][j1][j2] = ans+ grid[i][j1] + ((j1 == j2) ? 0 : grid[i][j2]);
}

int cherryPickup(vector<vector<int>> &grid) {
    n = grid.size();
    m = grid[0].size();
    memset(mem, -1, sizeof mem);
    return dp(0, 0, m - 1, grid);

}
};