class Solution {
public:
int minSwaps(vector<int> &nums) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + nums[i];
    }
    int ones = pre[n];
    int ans = 1e9;
    for (int i = 0; i <= n - ones; ++i) {
        ans = min(ans, ones - pre[i + ones] + pre[i]);
    }
    for (int i = n - ones+1; i < n; ++i) {
        ans = min(ans, pre[i] - pre[i - n + ones]);
    }
    return ans;
}
};