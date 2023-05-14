class Solution {
public:
vector<int>mem;
int dp(vector<int>&nums,int mask,int index){
    if(index*2>nums.size())
        return 0;
    if(mem[mask]!=-1)
        return mem[mask];
    int mx=0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            if(!(mask&(1<<i))&&!(mask&(1<<j))){
                int cur=(index*__gcd(nums[i],nums[j]))+dp(nums,mask+(1<<i)+(1<<j),index+1);
                mx=max(mx,cur);
            }
        }
    }
    return mem[mask]=mx;
}
int maxScore(vector<int>& nums) {
int n=nums.size();
mem.assign((1<<n),-1);
    return dp(nums,0,1);
}
};