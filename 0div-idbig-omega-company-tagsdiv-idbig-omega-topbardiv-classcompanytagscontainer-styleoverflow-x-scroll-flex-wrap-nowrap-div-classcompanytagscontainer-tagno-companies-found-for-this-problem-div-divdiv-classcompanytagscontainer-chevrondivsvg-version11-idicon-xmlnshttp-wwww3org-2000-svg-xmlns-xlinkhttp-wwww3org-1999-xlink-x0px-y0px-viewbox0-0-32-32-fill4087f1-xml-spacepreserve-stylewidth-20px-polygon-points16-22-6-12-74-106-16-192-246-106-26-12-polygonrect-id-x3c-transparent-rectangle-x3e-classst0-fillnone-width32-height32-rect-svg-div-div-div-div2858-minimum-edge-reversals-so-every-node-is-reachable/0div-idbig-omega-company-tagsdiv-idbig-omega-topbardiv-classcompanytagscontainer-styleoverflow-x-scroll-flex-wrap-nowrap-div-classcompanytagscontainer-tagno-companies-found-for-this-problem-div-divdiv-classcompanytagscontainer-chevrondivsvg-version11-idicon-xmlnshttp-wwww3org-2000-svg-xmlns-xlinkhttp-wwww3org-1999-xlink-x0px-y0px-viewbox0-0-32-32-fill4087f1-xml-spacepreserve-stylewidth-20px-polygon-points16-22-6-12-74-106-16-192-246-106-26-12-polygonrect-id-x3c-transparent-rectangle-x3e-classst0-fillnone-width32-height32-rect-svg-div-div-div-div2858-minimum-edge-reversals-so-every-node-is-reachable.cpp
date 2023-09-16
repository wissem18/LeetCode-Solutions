class Solution {
public:
void dfs(int node,vector<int>&res, vector<vector<int>> &graph,vector<vector<int>> &graph_rev,vector<bool>&vis){
    vis[node]=true;
    for (int i = 0; i < graph[node].size(); ++i) {
        if(!vis[graph[node][i]])
        {
            res[graph[node][i]]=res[node]+1;
            dfs(graph[node][i],res,graph,graph_rev,vis);
        }
    }
    for (int i = 0; i < graph_rev[node].size(); ++i) {
        if(!vis[graph_rev[node][i]])
        {
            res[graph_rev[node][i]]=res[node]-1;
            dfs(graph_rev[node][i],res,graph,graph_rev,vis);
        }
    }
}
vector<int> minEdgeReversals(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n), graph_rev(n);
    for (int i = 0; i < edges.size(); i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        graph[x].push_back(y);
        graph_rev[y].push_back(x);
    }

    queue<int> q;
    vector<int> visited(n, 0);
    q.push(0);
    int ans = 0;
    while (!q.empty()) {
        int curr = q.front();
        visited[curr] = 1;
        int count = 0;
        q.pop();
        for (int i = 0;i < graph[curr].size();i++) {
            if (!visited[graph[curr][i]]) {
                q.push(graph[curr][i]);
            }
        }
        for (int i = 0;
             i < graph_rev[curr].size();i++) {
            if (!visited[graph_rev[curr][i]]) {
                q.push(graph_rev[curr][i]);
                count++;
            }
        }
        ans += count;
    }
    vector<int>res(n);
    res[0]=ans;
    vector<bool>vis(n,false);
    dfs(0,res,graph,graph_rev,vis);
    return res;
}
};