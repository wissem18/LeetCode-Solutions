class Solution {
public:
int n;
vector<vector<vector<int>>>mem;
int dp(int p,int i,int m,vector<int>&a){
    if(i==n)
        return 0;
   if(mem[p][i][m]!=-1)
       return mem[p][i][m];
   int ans;
  if(p==0){
      ans=0;
      for (int j = 1; j <=2*m ; ++j) {
          if(i+j>n)
              break;
          ans=max(ans,a[i+j]-a[i]+dp(1,i+j,max(m,j),a));
      }
  }
  else{
      ans=1e9;
      for (int j = 1; j <=2*m ; ++j) {
          if(i+j>n)
              break;
          ans=min(ans,dp(0,i+j,max(m,j),a));
      }
  }
    return mem[p][i][m]=ans;
}
int stoneGameII(vector<int>& piles) {
n=piles.size();
vector<int>pre(n+1,0);
    for (int i = 0; i < n; ++i) {
        pre[i+1]=piles[i]+pre[i];
    }
mem.assign(2,vector<vector<int>>(n,vector<int>(5000,-1)));
    return dp(0,0,1,pre);
}
};