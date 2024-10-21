class Solution {
public:

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int node) {
    vis[node] = true;
    for (auto c: adj[node]) {
        if (!vis[c])
            dfs(c);
    }
    return;
}

bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();
    adj.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < rooms[i].size(); ++j) {
            adj[i].push_back(rooms[i][j]);
        }
    }
    vis.assign(n, false);
    dfs(0);
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            return false;
    }
    return true;
}
};