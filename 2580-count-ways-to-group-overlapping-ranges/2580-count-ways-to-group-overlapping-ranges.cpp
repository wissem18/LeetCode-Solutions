class Solution {
public:
    int MOD;
int dp(int i,int x,int mx,int &n,vector<vector<int>>& ranges,vector<vector<int>>&mem){
    if(i==n)
        return 1;
    if(mem[i][x]!=-1)
        return mem[i][x];
    if(ranges[i][0]<=mx)
        return mem[i][x]=dp(i+1,x,max(mx,ranges[i][1]),n,ranges,mem)%MOD;
    else
        return mem[i][x]=(dp(i+1,0,max(mx,ranges[i][1]),n,ranges,mem)%MOD+dp(i+1,1,max(mx,ranges[i][1]),n,ranges,mem)%MOD)%MOD;
}
    
int countWays(vector<vector<int>>& ranges) {
int n=ranges.size();
sort(ranges.begin(),ranges.end());
vector<vector<int>>mem(n,vector<int>(2,-1));
    MOD=1e9+7;
return (dp(1,0,ranges[0][1],n,ranges,mem)+dp(1,1,ranges[0][1],n,ranges,mem))%MOD;
}
};