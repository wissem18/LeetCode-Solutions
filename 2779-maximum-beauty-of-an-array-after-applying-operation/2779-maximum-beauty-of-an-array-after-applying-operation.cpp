class Solution {
public:
int maximumBeauty(vector<int> &nums, int k) {
    vector<int> pre(2e5 + 2, 0);
    for (auto num: nums) {
        pre[num + 1]++;
    }
    for (int i = 1; i <= 2e5 + 1; ++i) {
        pre[i] += pre[i - 1];
    }
    int ans = 1;
    for (int i = 1; i + 2 * k <= 2e5 + 1; ++i) {
        int range = pre[i + 2 * k] - pre[i - 1];
        ans = max(ans, range);
    }
    return ans;
}
};