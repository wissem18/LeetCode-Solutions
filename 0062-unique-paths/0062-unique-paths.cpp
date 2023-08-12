class Solution {
public:
vector<vector<int>>mem;
int dp(int m, int n) {
    if (m==0 && n==0) {
        return 1;
    }
    if (mem[m][n] != -1)
        return mem[m][n];
    int ans = 0;
    if (m-1>=0)
        ans += dp(m-1,n);

    if (n-1>=0)
        ans += dp(m,n-1);
    return mem[m][n] = ans;
}

int uniquePaths(int m, int n) {
mem.assign(m,vector<int>(n,-1));
return dp(m-1,n-1);
}
};