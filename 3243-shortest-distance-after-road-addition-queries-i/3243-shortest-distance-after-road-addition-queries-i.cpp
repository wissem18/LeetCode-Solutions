class Solution {
public:
vector<vector<int>> adj;

int bfs(int &n) {
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    int ans = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int cur = q.front();
            q.pop();
            if (cur == n - 1)
                return ans;
            for (auto child: adj[cur]) {
                if (!vis[child]) {
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
        ans++;
    }
    return -1;

}

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
    adj.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        adj[i].push_back(i + 1);
    }
    vector<int> ans;
    for (auto q: queries) {
        adj[q[0]].push_back(q[1]);
        ans.push_back(bfs(n));
    }
    return ans;
}
};