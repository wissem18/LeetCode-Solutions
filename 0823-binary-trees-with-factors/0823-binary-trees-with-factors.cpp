class Solution {
public:
    int MOD=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
         long long ans = 0;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;
        for (int i = 0; i < arr.size(); ++i) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; ++j)
                if (arr[i] % arr[j] == 0)
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % MOD;
            ans = (ans + dp[arr[i]]) % MOD;
        }
        return ans;
    }
};