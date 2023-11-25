class Solution {
public:
vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + nums[i];
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int l=pre[i];
        int r=pre[n]-pre[i+1];
        int cur=(i*nums[i]-l)+(r-(n-i-1)*nums[i]);
        ans.push_back(cur);
    }
    return ans;
}
};