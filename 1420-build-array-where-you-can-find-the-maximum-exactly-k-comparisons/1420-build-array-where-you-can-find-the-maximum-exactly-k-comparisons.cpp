class Solution {
public:
int MOD = 1e9 + 7;
int mem[50][101][51];
int dp(int i,int mx,int cost,int &m,int &n){
    if(cost<0)
        return 0;
    if(i==n)
        return (cost==0);
    if(mem[i][mx][cost]!=-1)
        return mem[i][mx][cost];
    int ans=(dp(i+1,mx, cost,m,n)*1LL*mx)%MOD;
    for (int j = mx+1; j <=m ; ++j) {
        ans=(ans+dp(i+1,j, cost-1,m,n))%MOD;
    }
    return mem[i][mx][cost]=ans;
}
int numOfArrays(int n, int m, int k) {
    memset(mem,-1,sizeof mem);
return dp(0,0,k,m,n);
}
};