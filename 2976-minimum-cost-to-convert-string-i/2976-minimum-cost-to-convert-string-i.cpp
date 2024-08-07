class Solution {
public:
long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost) {
    //build the graph of changes adjacency matrix
    vector<vector<long long>> graph(26, vector<long long>(26, 1e9));
    int n = original.size();
    for (int i = 0; i < n; ++i) {
        int from = original[i] - 'a';
        int to = changed[i] - 'a';
        graph[from][to] = min(graph[from][to], 1LL * cost[i]);
    }
    // apply floyd-warshall algorithm to get min move from one character to character
    vector<vector<long long>> dist(26, vector<long long>(26, 1e18));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == j) dist[i][j] = 0;
            else if (graph[i][j] != 1e9) dist[i][j] = graph[i][j];
            else dist[i][j] = 1e18;
        }
    }
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]);
            }
        }
    }
    // after that we must change each character from source to the character in target
    long long ans = 0;
    for (int i = 0; i < source.size(); ++i) {
        int from = source[i] - 'a';
        int to = target[i] - 'a';
        if (dist[from][to] == 1e18)
            return -1;
        ans += dist[from][to];
    }
    return ans;
}
};