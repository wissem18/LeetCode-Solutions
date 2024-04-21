class Solution {
public:
 vector<vector<int>> adj;
vector<bool>vis;
void dfs(int x){
    vis[x]=true;
    for (auto c:adj[x]) {
     if(!vis[c])
         dfs(c);
    }
    return;
}
bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
    adj.resize(n);
    for (auto e: edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
   vis.assign(n,false);
   dfs(source); 
   return vis[destination]; 
}
};