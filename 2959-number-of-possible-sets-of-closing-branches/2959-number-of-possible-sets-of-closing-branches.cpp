class Solution {
public:
int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads) {

    int ans = 0;
    for (int x = 0; x < (1 << n); ++x) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (auto r: roads) {
            dist[r[0]][r[1]] = min(r[2], dist[r[0]][r[1]]);
            dist[r[1]][r[0]] = min(r[2], dist[r[1]][r[0]]);
        }
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        for (int k = 0; k < n; k++) {
            if (x & (1 << k))
                for (int i = 0; i < n; i++) {
                    if (x & (1 << i))
                        for (int j = 0; j < n; j++) {
                            if (x & (1 << j))
                                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                }
        }
        bool test = true;
        for (int i = 0; i < n; ++i) {
            if (x & (1 << i))
                for (int j = 0; j < n; ++j) {
                    if (x & (1 << j))
                        if (dist[i][j] > maxDistance) {
                            test = false;
                            break;
                        }
                }
        }
        if (test)
            ans++;
    }
    return ans;
}
};