class Solution {
public:

vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> rows(n, 0);
    vector<int> cols(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rows[i] += grid[i][j];
            cols[j] += grid[i][j];
        }
    }
    vector<vector<int>>ans(n,vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[i][j]=rows[i]+cols[j]-(n-rows[i])-(m-cols[j]);
        }
    }
    return ans;
}
};