class Solution {
public:
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    for (auto v: adj[u]) {
        if (!vis[v])
            dfs(v);
    }
}

int removeStones(vector<vector<int>> &stones) {
    int n = stones.size();

    adj.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stones[i][0] == stones[j][0] ||
                stones[i][1] == stones[j][1]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int nbcomp = 0;
    vis.assign(n, false);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            nbcomp++;
        }
    }
    return n - nbcomp;
}
};