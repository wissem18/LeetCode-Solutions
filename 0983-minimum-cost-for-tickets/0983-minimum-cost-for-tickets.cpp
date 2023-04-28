class Solution {
public:
int n;
vector<int>pos;
vector<int>mem;
int dp(int i,vector<int>& days,vector<int>& costs){
    if(i>=n){
        return 0;
    }
    if(mem[i]!=-1)
        return mem[i];
   // int x= upper_bound(days.begin(),days.end(),days[i]+6)-days.begin();
   // int y=upper_bound(days.begin(),days.end(),days[i]+29)-days.begin();
    return mem[i]=min({costs[0]+dp(i+1,days,costs),costs[1]+dp(pos[days[i]+6]+1,days,costs),costs[2]+dp(pos[days[i]+29]+1,days,costs)});
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
 n=days.size();
 mem.assign(n+1,-1);
 pos.resize(450);
    for (int i = 1; i < n; ++i) {
        for (int j = days[i-1]; j <days[i] ; ++j) {
            pos[j]=i-1;
        }
    }
    pos[days[n-1]]=n-1;
    for (int i = days[n-1]+1; i <=400 ; ++i) {
        pos[i]=n;
            }
return dp(0,days,costs);
}
};