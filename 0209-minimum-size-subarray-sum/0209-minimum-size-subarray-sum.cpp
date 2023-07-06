class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + nums[i];
    }
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        int x = lower_bound(pre.begin(), pre.end(), pre[i] + target) - pre.begin();
        if (x == n + 1) {
            break;
        }
        ans = min(x - i, ans);
    }
    return (ans == 1e9) ? 0 : ans;
}
};