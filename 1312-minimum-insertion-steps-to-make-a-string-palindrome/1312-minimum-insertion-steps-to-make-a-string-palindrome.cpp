class Solution {
public:
vector<vector<int>> mem;

int dp(int i, int j, string &s) {
    if (i >= j)
        return 0;
    if (mem[i][j] != -1)
        return mem[i][j];
    if (s[i] != s[j])
        mem[i][j] = min(1 + dp(i + 1, j, s), 1 + dp(i, j - 1, s));
    else
        mem[i][j] = dp(i + 1, j - 1, s);
    return mem[i][j];
}

int minInsertions(string s) {
    int n = s.size();
    mem.assign(n, vector<int>(n, -1));
    return dp(0, n - 1, s);
}
};