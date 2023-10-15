class Solution {
public:
  int MOD = 1e9 + 7;
vector<vector<int>>mem;
int dp(int steps, int cur, int &mx) {
    if(!steps){
        return !cur;
    }
    if(mem[steps][cur]!=-1)
        return mem[steps][cur];
    int ans=dp(steps-1,cur,mx)%MOD;
    if(cur>0)
        ans=(ans+dp(steps-1,cur-1,mx)%MOD)%MOD;
    if(cur<mx-1)
        ans=(ans+dp(steps-1,cur+1,mx)%MOD)%MOD;
    return mem[steps][cur]=ans;
}

int numWays(int steps, int arrLen) {
    int mx=min(arrLen,steps/2+1);
mem.assign(steps+1,vector<int>(mx,-1));

return dp(steps,0,mx);
}
};