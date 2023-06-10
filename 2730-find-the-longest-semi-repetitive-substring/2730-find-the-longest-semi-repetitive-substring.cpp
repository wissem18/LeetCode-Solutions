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
int l=0,r=0;
    while(l<=r&&r<n){
        string cur=s.substr(l,r-l+1);
        if(check(cur)){
            ans=max(ans,r-l+1);
            r++;
           
        }
        else{
            l++;
        }
    }
    return ans;
}
};