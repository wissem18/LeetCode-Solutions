class Solution {
public:
int mod = 1e9 + 7;
vector<vector<int>> mem;

int dp(int i, int target, int &k, int &n) {
    if (i == n)
        return !target;
    if(target<=0)
        return 0;
    if (mem[i][target] != -1)
        return mem[i][target];
    int ans = 0;
    for (int j = 1; j <= k; ++j) {
        ans = (ans + dp(i + 1, target - j, k, n)%mod) % mod;
    }
    return mem[i][target] = ans;
}

int numRollsToTarget(int n, int k, int target) {
    mem.assign(n, vector<int>(target + 1, -1));
    return dp(0, target, k, n);
}
};