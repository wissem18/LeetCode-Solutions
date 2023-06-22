class Solution {
public:
    vector<vector<int>>mem;
int dp(int i,int x,vector<int>& prices,int fee){
    if(i==prices.size()){
        if(!x)
            return 0;
        else
            return -1e9;
    }
    if(mem[i][x]!=-1)
        return mem[i][x];
    int ans=-1e9;
    if(!x){
        ans=max(dp(i+1,1,prices,fee)- prices[i],dp(i+1,0,prices,fee));
    }
    else{
        ans=max(dp(i+1,0,prices,fee)+ prices[i]-fee,dp(i+1,1,prices,fee));
    }
    return mem[i][x]=ans;
}
int maxProfit(vector<int>& prices, int fee) {
int n=prices.size();
mem.assign(n+1,vector<int>(2,-1));
return dp(0,0,prices,fee);
}
};