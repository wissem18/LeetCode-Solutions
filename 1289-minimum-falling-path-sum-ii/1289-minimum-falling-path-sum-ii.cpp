class Solution {
public:
vector<vector<int>>mem;

int dp(int i, int j, vector<vector<int>> &grid) {
    if (i == grid.size())
        return 0;

    if (mem[i][j] != -1)
        return mem[i][j];
    int ans = 1e9;
    for(int nj=0;nj<grid.size();nj++){
        if(nj==j)continue;
        ans=min(ans,dp(i+1,nj,grid)+grid[i][j]);
    }
    return mem[i][j] = ans;
}

int minFallingPathSum(vector < vector < int >> &grid) {
int n=grid.size();
if(n==1)
    return grid[0][0];
mem.assign(n,vector<int>(n,-1));
int ans=1e9;
    for (int i = 0; i < n; ++i) {
        ans=min(ans,dp(0,i,grid));
    }
    return ans;
}

};