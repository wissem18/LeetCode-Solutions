class Solution {
public:
vector<vector<int>> adj;
int shortest_cycle(int n)
{
    int ans = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        
        vector<int> distance(n, 1e9);
        vector<int> parent(n, -1);

        
        distance[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int child : adj[x]) {
                if (distance[child] == 1e9) {
                    distance[child] = 1 + distance[x];
                    
                    parent[child] = x;
                    q.push(child);
                }
                else if (parent[x] != child && parent[child] != x)
                    ans = min(ans, distance[x] + distance[child] + 1);
            }
        }
    }
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}
int findShortestCycle(int n, vector<vector<int>>& edges) {
adj.resize(n);
    for (auto e:edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    return shortest_cycle(n);
}
};