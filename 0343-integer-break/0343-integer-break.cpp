class Solution {
public:
vector<int>mem;
int dp(int n,int &old){
if(n==0)
    return 1;
if(mem[n]!=-1)
    return mem[n];
int ans=1;
    for (int i = 1; i <n+(old!=n) ; ++i) {
        ans=max(ans,dp(n-i,old)*i);
    }
    return mem[n]=ans;
}
int integerBreak(int n) {
    mem.assign(n+1,-1);
return dp(n,n);
}
};