class Solution {
public:
int MOD = 1e9 + 7;
int mem[101][101][101];
int dp(int i,int curgroup,int curprofit,int &n, int &minProfit, vector<int>& group, vector<int>& profit){
    if(i==profit.size())
        return (curprofit>=minProfit);
   if(mem[i][curgroup][curprofit]!=-1)
       return mem[i][curgroup][curprofit];
     mem[i][curgroup][curprofit]=dp(i+1,curgroup,curprofit,n,minProfit,group,profit)%MOD;
     if(curgroup+group[i]<=n)
         mem[i][curgroup][curprofit]= (mem[i][curgroup][curprofit]+dp(i+1,curgroup+group[i],min(minProfit,curprofit+profit[i]),n,minProfit,group,profit)%MOD)%MOD;
return mem[i][curgroup][curprofit];
}
int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    memset(mem,-1,sizeof mem);
return dp(0,0,0,n,minProfit,group,profit);
}
};