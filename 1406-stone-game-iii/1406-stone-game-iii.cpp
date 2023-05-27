class Solution {
public:
int n;
vector<int>mem;
int dp(int i,vector<int>&a){
    if(i==n)
        return 0;
   if(mem[i]!=-1)
       return mem[i];
   int ans=a[i+1]-a[i]-dp(i+1,a);
    for (int j = i+2; j <=min(i+3,n) ; ++j) {
        ans=max(ans,a[j]-a[i]-dp(j,a));
    }
  return mem[i]=ans;
}
string stoneGameIII(vector<int>& piles) {
n=piles.size();
vector<int>pre(n+1,0);
    for (int i = 0; i < n; ++i) {
        pre[i+1]=piles[i]+pre[i];
    }
mem.assign(n,-1);
    int x=dp(0,pre);
    if(x>0)
        return "Alice";
    else if(x<0)
        return "Bob";
    else
        return "Tie";

}
};