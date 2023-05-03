class Solution {
public:
    vector<vector<pair<int,int>>> adj;
vector<bool> vis;
int cnt;
void dfs(int p) {
    vis[p] = true;
    for (auto& [child,type]: adj[p]) {
        if (!vis[child]){
            cnt+=type;
            dfs(child);
        }
    }

}

int minReorder(int n, vector<vector<int>> &connections) {
    adj.resize(n);
    for (int i = 0; i < connections.size(); ++i) {
        adj[connections[i][0]].push_back({connections[i][1],1});
        adj[connections[i][1]].push_back({connections[i][0],0});
    }
    vis.resize(n);
    cnt=0;
    dfs(0);
    return cnt;
}
};