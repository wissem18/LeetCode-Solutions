class Solution {
public:
int maxWidthRamp(vector<int> &nums) {
    int n = nums.size();
    vector<pair<int, int>> ind;
    for (int i = 0; i < n; ++i) {
        ind.push_back(make_pair(nums[i], i));
    }
    sort(ind.begin(), ind.end());
    int ans = 0;
    int mn = 1e9;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, ind[i].second - mn);
        mn = min(mn, ind[i].second);
    }
    return ans;
}
};