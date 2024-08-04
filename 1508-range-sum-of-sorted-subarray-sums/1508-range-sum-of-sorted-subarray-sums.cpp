class Solution {
public:
long long MOD = 1e9 + 7;

int rangeSum(vector<int> &nums, int n, int left, int right) {
    vector<int> subSum;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = i; j < n; ++j) {
            cur += nums[j];
            subSum.push_back(cur);
        }
    }
    sort(subSum.begin(),subSum.end());
    int ans=0;
    for (int i = left-1; i <right ; ++i) {
        ans=(ans+subSum[i])%MOD;
    }
    return ans;
}
};