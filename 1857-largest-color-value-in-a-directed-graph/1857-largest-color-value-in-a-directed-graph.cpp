class Solution {
public:
vector<vector<int>>graph;
vector<bool> vis;
vector<bool> anc;
vector<vector<int>>occ;
int dfs(int p,string &colors){
    if(anc[p])
        return 1e9;
    if(vis[p])
        return occ[p][colors[p]-'a'];
    vis[p]=true;
    anc[p]=true;
    for (auto u :graph[p]) {
      if(dfs(u,colors)==1e9)
          return 1e9;
        for (int i = 0; i < 26; ++i) {
         occ[p][i]=max(occ[p][i],occ[u][i] );
        }
    }
    occ[p][colors[p]-'a']++;
    anc[p]=false;
    return occ[p][colors[p]-'a'];
}
int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n=colors.size();
    graph.resize(n);
    for (auto e:edges) {
     graph[e[0]].push_back(e[1]);
    }
    vis.assign(n,false);
    int ans=0;
      anc.assign(n,false);
    occ.assign(n,vector<int>(26,0));
    for (int i = 0; i < n; ++i) {
          
       ans=max(ans, dfs(i,colors));
    
        }
    if(ans==1e9)
        return -1;
    return ans;
}
};