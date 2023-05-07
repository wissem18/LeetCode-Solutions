class Solution {
public:
int n;
vector<vector<int>>mem;
int dp(int i,int k,vector<vector<int>>& piles){
    if(i==n)
        return 0;
    if(mem[i][k]!=-1)
        return mem[i][k];
    for (int j = 0; j <min((int)piles[i].size(),k+1); ++j) {
       mem[i][k]=max(mem[i][k],piles[i][j]+dp(i+1,k-j,piles));
    }

    return mem[i][k];
}
int maxValueOfCoins(vector<vector<int>>& piles, int k) {
n=piles.size();
vector<vector<int>>ans(n);
    for (int i = 0; i < n; ++i) {
       ans[i].push_back(0);
        for (int j = 0; j < piles[i].size(); ++j) {
            ans[i].push_back(ans[i].back()+piles[i][j]);
        }
    }
mem.assign(n+1,vector<int>(k+1,-1));
    return dp(0,k,ans);
}
};