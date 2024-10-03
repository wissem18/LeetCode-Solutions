class Solution {
public:
int minSubarray(vector<int> &nums, int p) {
    int mod = 0;
    for (auto x: nums) {
        mod = (x + mod) % p;
    }
    if (mod == 0)
        return 0;
    int cur = 0;
    unordered_map<int, int> lastocc;
    int ans = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
        cur = (cur + nums[i]) % p;
        int opp = (cur-mod + p) % p;
        if (!lastocc.count(opp)) {
            if (cur == mod)
                ans = min(ans, i + 1);
        } else {
            ans = min(ans, i - lastocc[opp]);
        }
        lastocc[cur] = i;
    }
    if (ans == nums.size())
        return -1;
    return ans;
}
};