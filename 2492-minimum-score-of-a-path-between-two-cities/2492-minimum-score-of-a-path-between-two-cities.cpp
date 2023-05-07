class Solution {
public:
 void dfs(int i, vector<vector<pair<int, int>>> &adj, vector<bool> &vis, int &ans) {
    vis[i] = true;
    for (auto x: adj[i]) {
        if (!vis[x.first]||x.second<ans) {
            ans = min(ans, x.second);
            dfs(x.first, adj, vis, ans);
        }
    }
}

int minScore(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < roads.size(); ++i) {
        adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }
    vector<bool> vis(n + 1, false);
   int ans=1e9;
   dfs(1,adj,vis,ans);
   return ans;
}
};