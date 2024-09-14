class Solution {
public:
int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    int mx = *max_element(nums.begin(), nums.end());
    int mxind = max_element(nums.begin(), nums.end()) - nums.begin();
    int ans = 0;
    int cur=0;
    for (int i = mxind; i < n; ++i) {
        if (nums[i] == mx)
            cur++;
        else
        {
            ans=max(ans,cur);
            cur=0;
        };
    }
    ans=max(ans,cur);
    return ans;

}
};