class Solution {
public:
vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
    int n = nums.size();
    vector<int> ans(n);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur ^= nums[i];
        int k = 0;
        for (int j = 0; j < maximumBit; ++j) {
            if (((1 << j) & cur) == 0)
                k += (1 << j);
        }
        ans[n - i - 1] = k;
    }
    return ans;
}
};