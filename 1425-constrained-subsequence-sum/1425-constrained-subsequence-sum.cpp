class Solution {
public:
int constrainedSubsetSum(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> q;
    q.push({nums[0], 0});
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        while (i - q.top().second > k) {
            q.pop();
        }

        int curr = max(0, q.top().first) + nums[i];
        ans = max(ans, curr);
        q.push({curr, i});
    }

    return ans;
}
};