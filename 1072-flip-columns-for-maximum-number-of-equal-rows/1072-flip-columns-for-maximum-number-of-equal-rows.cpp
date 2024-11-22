class Solution {
public:
int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    map<vector<int>, int> occ;
    for (int i = 0; i < matrix.size(); ++i) {
        occ[matrix[i]]++;
    }
    int ans = 0;
    for (auto &[vec, nb]: occ) {
        int cur = nb;
        vector<int> a = vec;
        for (int i = 0; i < a.size(); ++i) {
            a[i] = a[i] ^ 1;
        }
        cur += occ[a];
        ans = max(ans, cur);
    }
    return ans;
}
};