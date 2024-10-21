class Solution {
public:
int pivotIndex(vector<int> &nums) {
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + nums[i];
    }
    for (int i = 0; i < n; ++i) {
        if (pre[i] == pre[n] - pre[i + 1])
            return i;
    }
    return -1;
}
};