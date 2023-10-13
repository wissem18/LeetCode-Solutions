class Solution {
public:
int n;
vector<int>mem;
int dp(int i,vector<int>& cost){
    if(i>=n)
        return 0;
    if(i==-1)
        return min(dp(0,cost),dp(1, cost));
    if(mem[i]!=-1)
        return mem[i];
    return mem[i]=cost[i]+min(dp(i+1, cost),dp(i+2,cost));
}
int minCostClimbingStairs(vector<int>& cost) {
n=cost.size();
mem.assign(n,-1);
return dp(-1,cost);
}
};