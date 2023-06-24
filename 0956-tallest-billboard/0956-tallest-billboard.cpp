class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
    int n = rods.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum+=rods[i];
    }
    int limit = 2*sum + 1;
    vector<vector<int>> dp(n+1, vector<int>(limit, INT_MIN));
    dp[0][sum] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < limit; j++) {
            if ((j - rods[i-1]) >= 0 && dp[i-1][j - rods[i-1]] != INT_MIN)
                dp[i][j] = max(dp[i][j], dp[i-1][j - rods[i-1]] + rods[i-1]);
            if ((j + rods[i-1]) < limit && dp[i-1][j + rods[i-1]] != INT_MIN)
                dp[i][j] = max(dp[i][j], dp[i-1][j + rods[i-1]]);
            if (dp[i-1][j] != INT_MIN)
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    return dp[n][sum];
}
};