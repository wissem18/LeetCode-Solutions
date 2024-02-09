class Solution {
public:
vector<int> largestDivisibleSubset(vector<int> &nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<int>dp(n,0);
    vector<int>par(n,-1);
    int mx=0,mxind=0;
    for (int i = n-1; i >=0 ; --i) {
        for (int j = i; j <n ; ++j) {
            if(nums[j]%nums[i]==0&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                par[i]=j;
            }
            if(dp[i]>mx){
                mx=dp[i];
                mxind=i;
            }
        }
    }
    vector<int>ans;
    for (int i = 0; i < mx; ++i) {
        ans.push_back(nums[mxind]);
        mxind=par[mxind];
    }
    return ans;
}
};