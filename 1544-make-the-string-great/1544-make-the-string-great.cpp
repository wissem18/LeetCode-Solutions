class Solution {
public:
string apply(string s){
    string ans="";

    for(int i=0;i<s.size();i++){
        if(i==s.size()-1){
            ans+=s[i];
            continue;
        }
        if(tolower(s[i])== tolower(s[i+1])&&s[i]!=s[i+1])
            i++;
        else
            ans+=s[i];
    }
    return ans;  
}
string makeGood(string s) {
    string ans=s;
    while(apply(ans).size()!=ans.size())
        ans= apply(ans);
    return ans;
}
};