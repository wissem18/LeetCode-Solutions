class Solution {
public:
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int x) {
    vis[x] = true;
    for (auto c: adj[x]) {
        if (vis[c])
            continue;
        dfs(c);
    }
}


vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    adj.resize(n);
//build the reversed graph
    for (auto e: edges) {
        adj[e[1]].push_back(e[0]);
    }
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; ++i) {
        vis.assign(n, false);
        dfs(i);
        for (int j = 0; j < n; ++j) {
            if (vis[j] && j != i)
                ans[i].push_back(j);
        }
    }
    return ans;

}
};