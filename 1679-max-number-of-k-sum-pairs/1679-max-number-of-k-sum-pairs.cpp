class Solution {
public:
int maxOperations(vector<int> &nums, int k) {
    int n = nums.size();
    map<int, int> occ;
    for (int i = 0; i < n; ++i) {
        if (nums[i] >= k)
            continue;
        occ[nums[i]]++;
    }
    int ans=0;
    for (auto &[num, cnt]: occ) {
        ans += min(cnt, occ[k - num]);
    }
    ans /= 2;
    return ans;
}
};