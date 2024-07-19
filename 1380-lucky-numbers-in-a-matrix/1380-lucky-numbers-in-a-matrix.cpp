class Solution {
public:
vector<int> luckyNumbers(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans;
    set<pair<int, int>> mins;
    for (int i = 0; i < n; ++i) {
        int mn = 1e9, mnind = 0;
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] < mn) {
                mn = matrix[i][j];
                mnind = j;
            }
        }
        mins.insert({i, mnind});
    }
    for (int i = 0; i < m; ++i) {
        int mx = 0, mxind = 0;
        for (int j = 0; j < n; ++j) {
            if (matrix[j][i] > mx) {
                mx = matrix[j][i];
                mxind = j;
            }
        }
        if (mins.count({mxind, i}))
            ans.push_back(matrix[mxind][i]);
    }
    return ans;
}
};