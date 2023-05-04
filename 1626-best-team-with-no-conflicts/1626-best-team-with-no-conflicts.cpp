class Solution {
public:
    int n;
    vector<pair<int,int>>a;
    int mem[1002][1002];
    int dp(int i,int minage){
    if(i==n)
        return 0;
        if(mem[i][minage]!=-1)
         return mem[i][minage];
    if(a[i].second>minage)
        return mem[i][minage]=dp(i+1,minage);
    return mem[i][minage]=max(dp(i+1,minage),dp(i+1,min(minage,a[i].second))+a[i].first);
   
}
int bestTeamScore(vector<int>& scores, vector<int>& ages) {

   n=scores.size();
   a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i]= make_pair(scores[i],ages[i]);
    }
    sort(a.begin(),a.end(),greater<>());
    memset(mem,-1,sizeof mem);
    return dp(0,1001);
}
};