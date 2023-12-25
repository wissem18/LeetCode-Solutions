class Solution {
public:

vector<int>mem;
int dp(int i,string &s) {
    if (i==s.size())
        return 1;
    if (s[i] == '0')
        return 0;
    if(mem[i]!=-1)
        return mem[i];
    int ans = dp(i+1,s);
    if (i+1 <s.size()) {
        string x;
        x+=s[i];
        x+=s[i+1];
        if (stoi(x) >= 10 && stoi(x) <= 26)
            ans += dp(i+2,s);
    }
    return mem[i]=ans;
}

int numDecodings(string s) {
    mem.assign(s.size(),-1);
    return dp(0,s);
}
};