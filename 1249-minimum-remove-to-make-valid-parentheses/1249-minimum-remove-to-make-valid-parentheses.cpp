class Solution {
public:
string minRemoveToMakeValid(string s) {
    int cnt = 0;
    string ans = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            cnt++;
        else if (s[i] == ')')
            cnt--;
        if (cnt < 0 && s[i] == ')') {
            cnt++;
            s[i] = '#';
            continue;
        }
    }
    for (int i = s.size(); i>=0; --i) {
        if(cnt<=0)
            break;
        if(s[i]=='('){
            s[i]='#';
            cnt--;
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]!='#')
            ans+=s[i];
    }
    return ans;
}
};