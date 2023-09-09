class Solution {
public:
    vector<int>mem;
int dp(vector<int>& nums, int target ){
    if(target<=0){
        return target==0;
    }
    if(mem[target]!=-1)
        return mem[target];
    int ans=0;
    for (int i = 0; i < nums.size(); ++i) {
        ans+=dp(nums,target-nums[i]);
    }
    return mem[target]=ans;
}
int combinationSum4(vector<int>& nums, int target) {
mem.assign(target+1,-1);
return dp(nums,target);
}
};