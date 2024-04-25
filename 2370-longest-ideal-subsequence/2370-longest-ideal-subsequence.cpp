class Solution {
public:
vector<vector<int>> mem;

int dp(int i, int prev, int &k, string &s) {
    if (i == s.size())
        return 0;
    if (mem[i][prev] != -1)
        return mem[i][prev];
    int ans = dp(i + 1, prev, k, s);
    if (abs(prev - (s[i] - 'a')) <= k)
        ans = max(ans, 1 + dp(i + 1, s[i] - 'a', k, s));
    return mem[i][prev] = ans;
}

int longestIdealString(string s, int k) {
    int n = s.size();
    int ans=0;
    mem.assign(n,vector<int>(26,-1));
    for(int i=0;i<26;i++){
        
        ans=max(ans, dp(0,i,k,s));
    }
    return ans;
}
};