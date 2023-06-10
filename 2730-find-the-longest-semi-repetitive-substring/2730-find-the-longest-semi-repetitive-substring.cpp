class Solution {
public:
bool check(string s){
    int cnt=0;
    for (int i = 1; i <s.size() ; ++i) {
        if(s[i-1]==s[i])
            cnt++;
        if(cnt>1)
            return false;
    }
    return true;
}
int longestSemiRepetitiveSubstring(string s) {
int n=s.size();
int ans=0;
    for (int i = 0; i < n; ++i) {
        string cur="";
        for (int j = i; j < n; ++j) {
         cur+=s[j];
         if(!check(cur)){
             cur.pop_back();
             break;
         }
        }
        ans=max(ans,(int)cur.size());
    }
    return ans;
}
};