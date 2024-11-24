class Solution {
public:
long long maxMatrixSum(vector<vector<int>> &matrix) {
    long long ans = 0;
    int mn = 1e9;
    int cnt = 0;
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += abs(matrix[i][j]);
            mn = min(mn, abs(matrix[i][j]));
            if (matrix[i][j] < 0)
                cnt++;
        }
    }
    if (cnt % 2)
        ans -= (2*mn);
    return ans;

}
};