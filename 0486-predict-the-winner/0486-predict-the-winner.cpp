class Solution {
public:
    int mem[25][25];
int dp(int l,int r,vector<int>& nums){
if(mem[l][r]!=-1)
    return mem[l][r];
if(l==r)
    return nums[l];
return mem[l][r]=max(nums[l]-dp(l+1,r,nums),nums[r]-dp(l,r-1,nums));
}
bool PredictTheWinner(vector<int>& nums) {
    int n=nums.size();
    memset(mem,-1,sizeof(mem));
    return dp(0,n-1,nums)>=0;
}
};