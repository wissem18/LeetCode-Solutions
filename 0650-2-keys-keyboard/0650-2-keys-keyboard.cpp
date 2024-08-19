class Solution {
public:
vector<vector<int>> mem;

int dp(int cur, int paste, int &n) {
    if (cur == n)
        return 0;
    if (cur > n)
        return 1e9;
    if (mem[cur][paste] != -1)
        return mem[cur][paste];
    int ans = 1e9;
    ans = min({ans, 1 + dp(cur + paste, paste, n), 2 + dp(cur * 2, cur, n)});
    return mem[cur][paste] = ans;
}

int minSteps(int n) {
    if(n==1)
        return 0;
    mem.assign(n, vector<int>(n, -1));
    return 1+dp(1, 1, n);
}
};