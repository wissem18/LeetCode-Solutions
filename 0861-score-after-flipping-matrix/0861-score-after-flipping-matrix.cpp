class Solution {
public:
int matrixScore(vector<vector<int>> &grid) {
//To maximize the score first we must make the first column all set with doing operation on rows that have 0 in first pos
// After that we will maximize the number of ones in each column by flipping the columns that have zeros more than ones
int n=grid.size();
int m=grid[0].size();
int ans=(1<<(m-1))*n;
    for (int j = 1; j < m; ++j) {
        int cnt=0;
        for (int i = 0; i < n; ++i) {
            int x=grid[i][j];
            if(!grid[i][0])
                x^=1;
            if(x)
                cnt++;
        }
        ans+=(1<<(m-j-1))*max(cnt,n-cnt);
    }
    return ans;
}
};