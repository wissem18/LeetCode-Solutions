class Solution {
public:
   vector<int>mem;
int dp(int i,vector<int>&a){
    if(i>=a.size())
        return 0;
    if(mem[i]!=-1)
     return mem[i];
    if(!a[i])
        return mem[i]= dp(i+1,a);
    return mem[i]=max(dp(i+2,a)+a[i]*i,dp(i+1,a));
}
int deleteAndEarn(vector<int>& nums) {
int mx=*max_element(nums.begin(),nums.end());
vector<int>a(mx+1,0);
    for (int i = 0; i < nums.size(); ++i) {
        a[nums[i]]++;
    }
    mem.assign(mx+1,-1);
    return dp(1,a);
}
};