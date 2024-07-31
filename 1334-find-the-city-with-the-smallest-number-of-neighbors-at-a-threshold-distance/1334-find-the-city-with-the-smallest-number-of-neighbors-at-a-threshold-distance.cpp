class Solution {
public:

vector<vector<pair<int, int>>> adj;

vector<vector<int>> dist;

// Dijkstra's algorithm to find shortest paths from a source city
void dijkstra(int n, int source) {
    // Priority queue to process nodes with the smallest distance first
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    fill(dist[source].begin(), dist[source].end(), INT_MAX);
    dist[source][source] = 0;

    while (!pq.empty()) {
        auto [currentDistance, currentCity] = pq.top();
        pq.pop();
        if (currentDistance > dist[source][currentCity]) {
            continue;
        }

        for (const auto &[neighborCity, edgeWeight]: adj[currentCity]) {
            if (dist[source][neighborCity] >
                currentDistance + edgeWeight) {
                dist[source][neighborCity] = currentDistance + edgeWeight;
                pq.push({dist[source][neighborCity], neighborCity});
            }
        }
    }
}


int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
    adj.resize(n);
    dist.assign(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;  // Distance to itself is zero
    }
    for (const auto &edge: edges) {
        int start = edge[0];
        int end = edge[1];
        int weight = edge[2];
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});

    }

    for (int i = 0; i < n; i++) {
        dijkstra(n, i);
    }
    int mn = INT_MAX, ans = -1;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (dist[i][j] <= distanceThreshold) {
                cnt++;
            }
        }

        if (cnt <= mn) {
            mn = cnt;
            ans = i;
        }
    }
    return ans;
}
};