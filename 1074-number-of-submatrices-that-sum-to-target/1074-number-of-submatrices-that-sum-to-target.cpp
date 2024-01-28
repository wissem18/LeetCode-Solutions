class Solution {
public:
int n, m;

vector<vector<int>> prefixSum2D(vector<vector<int>> &a) {
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            a[j][i] += a[j - 1][i];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            a[i][j] += a[i][j - 1];
        }
    }
 vector<vector<int>>mat(n+1,vector<int>(m+1,0));
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=m ; ++j) {
            mat[i][j]=a[i-1][j-1];
        }
    }
    return mat;
}

int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    n = matrix.size();
    m = matrix[0].size();
    vector<vector<int>>res=prefixSum2D(matrix);
    int ans = 0;
    for (int i = 0; i <=n ; ++i) {
        for (int j = i+1; j <=n ; ++j) {
            for (int k = 0; k <= m; ++k) {
                for (int l = k+1; l <= m; ++l) {
                    int sum=res[j][l]-res[i][l]-res[j][k]+res[i][k];
                    if(sum==target)
                        ans++;
                }
            }
        }
    }
    return ans;
}
};