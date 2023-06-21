class Solution {
public:
bool wordBreak(string s, vector<string>& wordDict) {
    int n=s.size();
    set<string>st;
    for (auto x:wordDict) {
        st.insert(x);
    }
    vector<int>dp(n+1,0);
    dp[0]=1;
    for (int i = 1; i <=n ; ++i) {
        for (int j = i-1; j >=0 ; --j) {
            if(dp[j]){
                string cur=s.substr(j,i-j);
                if(st.count(cur)){
                    dp[i]=true;
                    break;
                }
            }
        }
    }
    return dp[n];
}
};