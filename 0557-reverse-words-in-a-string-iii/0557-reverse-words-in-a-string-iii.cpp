class Solution {
public:
string reverseWords(string s) {
string ans="";
string cur="";
int n=s.size();
    for (int i = 0; i <n ; ++i) {
        if(s[i]==' '){
            reverse(cur.begin(),cur.end());
            ans+=cur;
            ans+=' ';
            cur="";
        }
        else
            cur+=s[i];
    }
    reverse(cur.begin(),cur.end());
    ans+=cur;
    return ans;
}
};