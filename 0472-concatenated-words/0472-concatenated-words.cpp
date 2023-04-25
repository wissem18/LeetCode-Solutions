class Solution {
public:
vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    sort(words.begin(),words.end());
    vector<string >result;
    for (int i = 0; i < words.size(); ++i) {
       int n=words[i].size();
       vector<int>dp(n+1,0);
       dp[0]=1;
        for (int j = 0; j < n; ++j) {
            if(dp[j]==0)//if there's not a concatenated word just before this position
                continue;
            for (int k = j+1; k <=n ; ++k) {
              string x=words[i].substr(j,k-j);
              if(x.size()<n&& (upper_bound(words.begin(),words.end(),x)!=lower_bound(words.begin(),words.end(),x)))
                  //if this that substring is an element of words and it's size is less than the size of all the string
                  dp[k]=1;
            }
        }
        if(dp[n])
            result.push_back(words[i]);
    }
    return result;
}
};