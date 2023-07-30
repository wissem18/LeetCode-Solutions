class Solution {
public:
    int mem[105][105];
int dp(int l,int r,string &s){
    if(mem[l][r]!=-1)
        return mem[l][r];
    int ans=100;
    int j=-1;
    for (int i = l; i <r ; ++i) {
        if(s[i]!=s[r]&&j==-1){
            j=i;
        }
        if(j!=-1)
            ans=min(ans,1+dp(j,i,s)+dp(i+1,r,s));
    }
    if(j==-1)
        ans=0;
    return mem[l][r]=ans;
}
int strangePrinter(string s) {
    int n = s.size();
    memset(mem,-1,sizeof(mem));
    return dp(0,n-1,s)+1;
}
};