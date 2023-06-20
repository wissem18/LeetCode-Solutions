class Solution {
public:
vector<int>mem;
int dp(int x,int &n){
    if(x==n)
        return 1;
    if(x>n)
        return 0;
    if(mem[x]!=-1)
        return mem[x];
    return mem[x]=(dp(x+1,n)+dp(x+2,n));
}
int climbStairs(int n) {
mem.assign(n+1,-1);
return dp(0,n);
}
};