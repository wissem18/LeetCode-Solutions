class Solution {
public:
vector<vector<int>>graph;
vector<bool>vis;
int ans=INT_MIN;
void dfs(int s,int t,vector<int>& informTime){
    vis[s]=true;
    ans=max(ans,t);
    for (auto x:graph[s]) {
       if(!vis[x])
           dfs(x,t+informTime[s],informTime);
    }
}
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    graph.resize(n);
      for (int i = 0; i < manager.size(); ++i) {
          if(i==headID){
              continue;
          }
          graph[manager[i]].push_back(i);
      }
      vis.assign(n,false);
      dfs(headID,0,informTime);
      return ans;
  }

};