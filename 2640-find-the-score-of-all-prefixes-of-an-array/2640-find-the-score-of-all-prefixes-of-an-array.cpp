class Solution {
public:
vector<long long> findPrefixScore(vector<int>& nums) {
vector<long long> ans;
   long long mx=0;
   long long cur=0;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i]>mx)
            mx=nums[i];
        ans.push_back(cur+nums[i]+mx);
        cur=ans[i];
    }
    return ans;
}
};