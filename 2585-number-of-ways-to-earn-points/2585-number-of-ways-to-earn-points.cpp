class Solution {
public:
const int MOD = 1e9+7;
int dp(int i,int cur,int n,int target,vector<vector<int>>& types,vector<vector<int>>& mem){
    if(i==n){
        if(cur==target)
            return 1;
        return 0;
    }
    if(mem[i][cur]!=-1)
        return mem[i][cur];
    int ans=0;
    for (int j = 0; j <=types[i][0]; ++j) {
        if(cur+j*types[i][1]>target)
            break;
      ans=(ans+dp(i+1,cur+j*types[i][1],n,target,types,mem))%MOD;
    }
    return mem[i][cur]=ans;
}
int waysToReachTarget(int target, vector<vector<int>>& types) {
vector<vector<int>>mem(types.size()+1,vector<int>(1005,-1));
return dp(0,0,(int)types.size(),target,types,mem);
}};