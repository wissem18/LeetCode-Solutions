class Solution {
public:
long long MOD = 1e9 + 7;
vector<vector<vector<int>>> mem;

int dp(int i, int totA, int conL) {
    if (totA > 1)
        return 0;
    if (conL > 2)
        return 0;
    if (i == 0) {
        return 1;
    }
    if (mem[i][totA][conL] != -1)
        return mem[i][totA][conL];
    int ans = ((dp(i - 1, totA, 0) % MOD + dp(i - 1, totA + 1, 0) % MOD) % MOD +
               dp(i - 1, totA, conL + 1) % MOD) % MOD;
    return mem[i][totA][conL] = ans;
}

int checkRecord(int n) {
mem.assign(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
return dp(n,0,0);
}
};