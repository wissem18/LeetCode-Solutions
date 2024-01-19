class Solution {
public:
    

vector<vector<int>> mem;
int n;
int dp(int i, int j, vector<vector<int>> &matrix) {
    if(j<0 || j>=n)
        return 1e9;
    if(i==0)
        return matrix[0][j];
    if(mem[i][j]!=1e9)
        return mem[i][j];
    return mem[i][j] = matrix[i][j]+min({dp(i-1,j,matrix),dp(i-1,j-1,matrix),dp(i-1,j+1,matrix)});
}

int minFallingPathSum(vector<vector<int>> &matrix) {
    n = matrix.size();
    int ans = 1e9;
    mem.assign(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp(n-1, i, matrix));
    }
    return ans;
}
    
};