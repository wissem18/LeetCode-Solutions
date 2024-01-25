class Solution {
public:
vector<vector<int>> mem;

int dp(int i, int j, string &s1, string &s2) {
    if (i == s1.size() || j == s2.size())
        return 0;

    if (mem[i][j] != -1)
        return mem[i][j];
    if (s1[i] == s2[j]) {
        return mem[i][j] = 1 + dp(i + 1, j + 1, s1, s2);
    }
    return mem[i][j] = max({dp(i + 1, j, s1, s2), dp(i, j + 1, s1, s2), dp(i + 1, j + 1, s1, s2)});
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    mem.assign(n, vector<int>(m, -1));
    return dp(0, 0, text1, text2);
}
};