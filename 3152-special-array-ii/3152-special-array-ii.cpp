class Solution {
public:
vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> pre(n, 0);
    for (int i = 1; i < nums.size(); ++i) {
        int cur = abs((nums[i - 1] % 2) - (nums[i] % 2));
        pre[i] = pre[i - 1] + cur;
    }
    vector<bool> ans;
    for (auto q: queries) {
        if (q[0] == q[1])
            ans.push_back(true);

        else
            ans.push_back(pre[q[1]] - pre[q[0]] == q[1] - q[0]);
    }
    return ans;
}
};