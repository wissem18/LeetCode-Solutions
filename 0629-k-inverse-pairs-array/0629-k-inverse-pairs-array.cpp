class Solution {
public:
int mod=1e9+7;
vector<vector<int>> mem;

int dp(int cur, int k) {
    if (cur == 0)
        return 0;
    if (k == 0)
        return 1;

    if (mem[cur][k] != -1)
        return mem[cur][k];
    //the element cur have cur positions to be placed in from right to left which contribue from 0 to cur-1 in order in the number of inversions
    int ans = 0;
    for (int i = 0; i <= min(cur-1,k); ++i) {
        ans=(ans+dp(cur-1,k-i))%mod;
    }
    return mem[cur][k]=ans;
}

int kInversePairs(int n, int k) {
mem.assign(n+1,vector<int>(k+1,-1));
return dp(n,k);
}
};