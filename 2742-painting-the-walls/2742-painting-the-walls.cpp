class Solution {
public:
int n;
vector<vector<int>>mem;
int dp(int i,int remain,vector<int>& cost, vector<int>& time){
if(remain<=0)
    return 0;
if(i==n)
    return 1e9;
if(mem[i][remain]!=-1)
    return mem[i][remain];
return mem[i][remain]=min(cost[i]+dp(i+1,remain-1-time[i], cost,time),dp(i+1,remain, cost,time));
}
int paintWalls(vector<int>& cost, vector<int>& time) {
n=cost.size();
mem.assign(n,vector<int>(n+1,-1));
return dp(0,n, cost,time);
}
};