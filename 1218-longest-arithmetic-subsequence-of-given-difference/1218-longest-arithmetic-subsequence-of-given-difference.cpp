class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int>dp;
        int ans=1;
        for(auto x:arr){
          dp[x]=dp.count(x-difference)?dp[x-difference]+1:1;
            ans=max(ans,dp[x]);
        }
        return ans;
    }
};