class Solution {
public:
    int n,m;
vector<vector<int>>mem;
bool dp(int i,int j,string &s1,string &s2,string &s3){
    if(i==n&&j==m)
        return true;
    if(mem[i][j]!=-1)
        return mem[i][j];
    bool ans=false;
    if(i<n&&s1[i]==s3[i+j])
        ans|=dp(i+1,j,s1,s2,s3);
    if(j<m&&s2[j]==s3[i+j])
        ans|=dp(i,j+1,s1,s2,s3);
    return mem[i][j]=ans;

}
bool isInterleave(string s1, string s2, string s3) {
if(s3.size()!=s1.size()+s2.size())
    return false;
else{
    n=s1.size();
    m=s2.size();
    mem.assign(n+1,vector<int>(m+1,-1));
    return dp(0,0,s1,s2,s3);
}
}
};