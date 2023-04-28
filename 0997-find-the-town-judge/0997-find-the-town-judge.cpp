class Solution {
public:
  int findJudge(int n, vector<vector<int>>& trust) {
   int vis[n+1];
    memset(vis,0,sizeof vis);
    for (int i = 0; i < trust.size(); ++i) {
       vis[trust[i][0]]=1;
    }
    int nb=0;
    int ans=0;
    for (int i = 1; i <=n ; ++i) {
        if(vis[i]){
            nb++;
        }
        else{
            ans=i;
        }
    }
    if(nb!=n-1)
        return -1;
    for (int i = 0; i < trust.size(); ++i) {
        if(trust[i][1]==ans){
            vis[trust[i][0]]=0;
        }
    }
    for (int i = 1; i <=n ; ++i) {
        if(vis[i])
            return -1;
    }
    return ans;

}
};