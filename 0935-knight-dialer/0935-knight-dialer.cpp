class Solution {
public:
int MOD = 1e9+7;
vector<vector<int>>mem;
vector<int>adj[10]={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
int dp(int i ,int cur,int &n){
    if(i==n-1)
        return 1;
    if(mem[i][cur]!=-1)
        return mem[i][cur];
    int ans=0;
    for (auto x:adj[cur]) {
        ans=(ans+dp(i+1,x,n))%MOD;
    }
    return mem[i][cur]=ans;
}
int knightDialer(int n) {
    int ans=0;
    mem.assign(n,vector<int>(10,-1));
    for(int i=0;i<10;i++){
        ans=(ans+dp(0,i,n))%MOD;
    }
    return ans;
}
};