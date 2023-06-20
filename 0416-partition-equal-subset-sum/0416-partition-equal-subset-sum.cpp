class Solution {
public:
vector<vector<int>>mem;
bool dp(int i,int cursum,int &sum,int &n,vector<int>&nums){
    if(sum==2*cursum)
        return true;
    if(i==n){
        return false;
    }
    if(mem[i][cursum]!=-1)
        return mem[i][cursum];
    return mem[i][cursum]=dp(i+1,cursum,sum,n,nums)||dp(i+1,min(cursum+nums[i],sum/2+1),sum,n,nums);
}
bool canPartition(vector<int>& nums) {
int sum=0;
int n=nums.size();
    for (int i = 0; i < n; ++i) {
        sum+=nums[i];
    }
if(sum%2)
    return false;
else{
mem.assign(n,vector<int>(sum/2+5,-1));
return dp(0,0,sum,n,nums);
}
}
};