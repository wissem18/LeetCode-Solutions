class Solution {
public:
int mod=1e9+7;
vector<vector<vector<int>>>mem;
int dp(int i,int j,int mx,int &n,int &m){
    if(mx<0)
        return 0;
    if(i==n||j==m||i<0||j<0)
        return 1;
    if(mem[i][j][mx]!=-1)
        return mem[i][j][mx];
    return mem[i][j][mx]=((dp(i-1,j,mx-1,n,m)%mod+dp(i,j-1,mx-1,n,m)%mod)%mod+(dp(i+1,j,mx-1,n,m)%mod+dp(i,j+1,mx-1,n,m)%mod)%mod)%mod;
}
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    mem.assign(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
    return dp(startRow,startColumn,maxMove,m,n);
}
};