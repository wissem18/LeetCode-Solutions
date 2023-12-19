class Solution {
public:
    
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
    int n = img.size();
    int m = img[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cnt = 1;
            int s = img[i][j];
            for (int k = 0; k < 8; ++k) {
                if (i + dx[k] < n && i + dx[k] >= 0 && j + dy[k] < m && j + dy[k] >= 0) {
                    cnt++;
                    s += img[i + dx[k]][j + dy[k]];
                }
            }
            ans[i][j] = s / cnt;
        }
    }
    return ans;
}
};