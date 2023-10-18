class Solution {
public:
int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
    vector<vector<int>> adj(n);
    for (auto x: relations) {
        adj[x[0] - 1].push_back(x[1] - 1);
    }
    vector<int> in_degree(n, 0);
    for (int u = 0; u < n; u++) {
        vector<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
            in_degree[*itr]++;
    }
    queue<int> q;
    vector<int> mx(n,0);
    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            q.push(i), mx[i] = time[i];

    vector<int> top_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);
        vector<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) {
            mx[*itr]=max(mx[*itr],mx[u]+time[*itr]);
            if (--in_degree[*itr] == 0)
                q.push(*itr);
        }
    }
    int ans=*max_element(mx.begin(),mx.end());
    return ans;
}
};