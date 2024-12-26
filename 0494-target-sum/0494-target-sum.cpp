class Solution {
public:
map<pair<int, int>, int> mem;

int dp(int i, int cursum, vector<int> &nums, int &target) {
    if (i == nums.size()) {
        return cursum == target;
    }
    if (mem.count({i, cursum}))
        return mem[{i, cursum}];
    int ans = dp(i + 1, cursum + nums[i], nums, target) + dp(i + 1, cursum - nums[i], nums, target);
    return mem[{i, cursum}] = ans;
}

int findTargetSumWays(vector<int> &nums, int target) {
    return dp(0, 0, nums, target);
}
};