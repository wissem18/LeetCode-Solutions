class Solution {
public:
int hamming_distance(string &a,string &b){
    int ans=0;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i]!=b[i])
            ans++;
    }
    return ans;
}

vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
vector<int>dp(n,1);
vector<int>par(n,-1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(groups[i]!=groups[j]&&words[i].size()==words[j].size()&& hamming_distance(words[i],words[j])==1){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    par[i]=j;
                }
            }
        }
    }
    vector<string>ans;
    int ind= max_element(dp.begin(),dp.end())-dp.begin();
    while(ind!=-1){
        ans.push_back(words[ind]);
        ind=par[ind];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
};