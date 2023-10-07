class Solution {
public:
    int MOD = 1e9 + 7;
int mem[50][101][51];
int dp(int i,int mx,int cost,int &n,int &m,int &k){
    if(i==n)
        return cost==k;
    if(mem[i][mx][cost]!=-1)
        return mem[i][mx][cost];
    int ans=0;
    for (int j = 1; j <=mx ; ++j) {
        ans=(ans+dp(i+1,mx, cost,n,m,k))%MOD;
    }
    for (int j = mx+1; j <=m ; ++j) {
        ans=(ans+dp(i+1,j, cost+1,n,m,k))%MOD;
    }
    return mem[i][mx][cost]=ans;
}
int numOfArrays(int n, int m, int k) {
    memset(mem,-1,sizeof mem);
return dp(0,0,0,n,m,k);
}
};