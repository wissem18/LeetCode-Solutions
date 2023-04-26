class Solution {
public:
vector<vector<int>>mem;
int dp(int i,int j,string &s){
    if(i>j)
        return 0;
    if(i==j)
        return 1;
    if(mem[i][j]!=-1)
        return mem[i][j];
    if(s[i]==s[j])
        return mem[i][j]=dp(i+1,j-1,s)+2;
    else
        return mem[i][j]=max(dp(i+1,j,s),dp(i,j-1,s));
}
int longestPalindromeSubseq(string s) {
int n=s.size();
mem.assign(n+1,vector<int>(n+1,-1));
return dp(0,n-1,s);
}
};