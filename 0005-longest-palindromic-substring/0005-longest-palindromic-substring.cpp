class Solution {
public:
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> isPal(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i <= n; ++i) {
        isPal[i][i] = true;
    }
    int mx = 1;
    string ans = "";
    ans+=s[0];
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
             if ((i>j-2||isPal[i + 1][j - 1]) && s[i] == s[j]) {
                isPal[i][j] = true;
                if(j-i+1>mx)
                mx=j-i+1,ans=s.substr(i,mx);
            }
        }
    }
    return ans;
}
};