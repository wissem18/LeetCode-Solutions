class Solution {
public:
    
vector<vector<long long>>mem;
long long dp(int i,int p,vector<int>& nums,int &k){
    if(i==nums.size()){
        if(p)
            return -1e9;
        else
            return 0;
    }
    if(mem[i][p]!=-1)
        return mem[i][p];
    
    long long ans=max(dp(i+1,p,nums,k)+nums[i],dp(i+1,p^1,nums,k)+(nums[i]^k));
    return mem[i][p]=ans;
}
long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
int n=nums.size();
mem.assign(n,vector<long long>(2,-1));
return dp(0,0,nums,k);
}
};