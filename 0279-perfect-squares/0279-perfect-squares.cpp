class Solution {
public:
vector<int>mem;
int dp(int n){
    if(n<0)
        return 1e9;
    if(n==0)
        return 0;
    if(mem[n]!=-1)
        return mem[n];
    int ans=1e9;
    for (int i = 1; i <=sqrt(n) ; ++i) {
        ans=min(ans,1+dp(n-i*i));
    }
    return mem[n]=ans;
}
int numSquares(int n) {
mem.assign(n+1,-1);
return dp(n);
}
};