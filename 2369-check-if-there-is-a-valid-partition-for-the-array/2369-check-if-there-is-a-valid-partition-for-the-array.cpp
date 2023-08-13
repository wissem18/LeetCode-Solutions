class Solution {
public:
    vector<int>mem;
bool dp(int i,vector<int>& nums){
    if(i<0)
        return true;
    if(mem[i]!=-1)
        return mem[i];
    bool ans=false;
    if (i > 0 && nums[i] == nums[i - 1]) {
        ans |= dp( i - 2,nums);
    }
    if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) {
        ans |= dp( i - 3,nums);
    }
    if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1) {
        ans |= dp( i - 3,nums);
    }
    return mem[i]=ans;
}
bool validPartition(vector<int>& nums) {
    int n=nums.size();
mem.assign(n,-1);
return dp(n-1,nums);
}
};