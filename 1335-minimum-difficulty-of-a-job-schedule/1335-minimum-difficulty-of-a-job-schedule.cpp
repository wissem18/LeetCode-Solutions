class Solution {
public:
int n;
vector<vector<int>>mem;
int dp(int i, int d, vector<int> &dif) {
    if (d < 0)
        return 1e9;
    if (i == n) {
        if (d == 0)
            return 0;
        else
            return 1e9;
    }
    if(mem[i][d]!=-1)
        return mem[i][d];
    int ans = 1e9;
    int mx = 0;
    for (int j = i; j < n; ++j) {
        mx = max(mx, dif[j]);
        ans = min(ans, dp(j + 1, d - 1, dif) + mx);
    }
    return mem[i][d]=ans;
}

int minDifficulty(vector<int> &jobDifficulty, int d) {
    n = jobDifficulty.size();
    if (n < d)
        return -1;
    else {
        mem.assign(n,vector<int>(d+1,-1));
        return dp(0, d, jobDifficulty);
    }
}
};