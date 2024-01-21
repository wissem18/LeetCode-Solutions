class Solution {
public:
vector<vector<int>> mem;

int dp(int i, int lst, vector<int> &nums) {
    if (i >= nums.size())
        return 0;
    if (mem[i][lst] != -1)
        return mem[i][lst];
    if (i == lst)
        return mem[i][lst] = max(nums[i] + dp(i + 1, i, nums), dp(i + 1, lst + 1, nums));
    if (i - lst == 1)
        return mem[i][lst] = dp(i + 1, lst, nums);
    return mem[i][lst] = max(nums[i] + dp(i + 1, i, nums), dp(i + 1, lst, nums));
}

int rob(vector<int> &nums) {
    int n = nums.size();
    mem.assign(n, vector<int>(n, -1));
    return dp(0, 0, nums);
}
};