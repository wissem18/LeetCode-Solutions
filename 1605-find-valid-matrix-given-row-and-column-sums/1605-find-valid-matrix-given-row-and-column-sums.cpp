class Solution {
public:
vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
    int n = rowSum.size();
    int m = colSum.size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<int> curRowSum(n, 0), curColSum(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[i][j] = min(rowSum[i] - curRowSum[i], colSum[j] - curColSum[j]);
            curColSum[j] += ans[i][j];
            curRowSum[i] += ans[i][j];
        }
    }
    return ans;
}
};