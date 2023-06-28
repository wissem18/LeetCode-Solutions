class Solution {
public:
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& pro, int start, int end) {
    vector<vector<pair<int, double>>> graph(n);
    for(int i=0; i<edges.size(); i++) {
        graph[edges[i][0]].push_back({edges[i][1], pro[i]});
        graph[edges[i][1]].push_back({edges[i][0], pro[i]});
    }
    vector<bool> vis(n, false);

    priority_queue<pair<double, int>> pq;
    pq.push({1.0, start});
    vector<double> mxp(n, 0.0);
    mxp[start] = 1.0;

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        double p = top.first;
        int node = top.second;
        if(!vis[node]) {
            vis[node]=true;
            for(auto &to: graph[node]) {
                if (mxp[to.first] < to.second*p) {
                    mxp[to.first] = to.second*p;
                    pq.push({mxp[to.first], to.first});
                }
            }
        }
    }
    return mxp[end];
}};