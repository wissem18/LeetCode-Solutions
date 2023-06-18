class Solution {
public:
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int MOD = 1e9+7;
vector<vector<int>>mem;
int n,m;
int dp(int x,int y,vector<vector<int>>& grid){
    if(mem[x][y]!=-1)
        return mem[x][y];
    int ans=1;
    for (int i = 0; i < 4; ++i) {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]>grid[x][y])
            ans=(ans+dp(nx,ny,grid))%MOD;
    }
    return mem[x][y]=ans;
}
int countPaths(vector<vector<int>>& grid) {
 n=grid.size();
 m=grid[0].size();
mem.assign(n+1,vector<int>(m,-1));
int ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans=(ans+dp(i,j,grid))%MOD;
        }
    }
    return ans;
}

};