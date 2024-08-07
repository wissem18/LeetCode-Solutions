class Solution {
public:
 int secondMinimum(int n, vector<vector<int>> &edges, int time, int change) {
    vector<int> dis(n + 1, INT_MAX), dis2(n + 1, INT_MAX);//min and second min paths
    vector<vector<int>> graph(n + 1);
    for (auto &e: edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    dis[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);
    while (pq.size()) {
        auto [cost, node] = pq.top();
        pq.pop();
        if (dis2[node] < cost) continue;
        for (auto c: graph[node]) {
            int new_cost = cost + time;
            // red
            if ((cost / change) % 2 == 1) {
                new_cost += change - (cost % change);
            }
            if (dis[c] > new_cost) {
                dis2[c] = dis[c];
                dis[c] = new_cost;
                pq.emplace(new_cost, c);
            } else if (new_cost > dis[c] && new_cost < dis2[c]) {
                dis2[c] = new_cost;
                pq.emplace(new_cost, c);
            }
        }
    }
    return dis2[n];
}
};