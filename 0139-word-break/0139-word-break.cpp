class Solution {
public:
set<string>st;
int n;
map<pair<int,string>,bool>mp;
bool dp(int i,string cur,string &s){
  if(i==n){
      return cur.empty();
  }
  if(mp.count({i,cur}))
      return mp[{i,cur}];
    bool ans=false;
  string nw=cur+s[i];
    if(st.count(nw)){
        ans|=dp(i+1,"",s);
    }
     ans|=dp(i+1,nw,s);

    return mp[{i,cur}]=ans;
}
bool wordBreak(string s, vector<string>& wordDict) {
n=s.size();
    for (auto x:wordDict) {
        st.insert(x);
    }
  return dp(0,"",s);
}
};