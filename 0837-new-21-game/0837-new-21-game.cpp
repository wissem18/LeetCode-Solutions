class Solution {
public:
double new21Game(int n, int k, int maxPts) {
    if(k==0)
        return 1.0;
    if(n>=k-1+maxPts)
        return 1.0;
    vector<double>dp(n+1,0.0);//the probaility to get i in a such step
    double ans = 0.0;
    double curSum = 1.0;//maintains the probality of numbers that we can get to i by adding a number from [1..maxPts]
    dp[0] = 1.0;
    for (int i = 1; i <= n; i++) {
        dp[i] = curSum / maxPts;

        if(i < k) curSum += dp[i];//the game didn't end we keep adding the probability to curSum
        else ans += dp[i];//if i>=K the game has ended we can cumulate so the probabilities
         
        if(i >= maxPts) curSum -= dp[i - maxPts];//to maintain the curSum always valid in the range[i-maxPts..i-1]
    }
    return ans;
}
};