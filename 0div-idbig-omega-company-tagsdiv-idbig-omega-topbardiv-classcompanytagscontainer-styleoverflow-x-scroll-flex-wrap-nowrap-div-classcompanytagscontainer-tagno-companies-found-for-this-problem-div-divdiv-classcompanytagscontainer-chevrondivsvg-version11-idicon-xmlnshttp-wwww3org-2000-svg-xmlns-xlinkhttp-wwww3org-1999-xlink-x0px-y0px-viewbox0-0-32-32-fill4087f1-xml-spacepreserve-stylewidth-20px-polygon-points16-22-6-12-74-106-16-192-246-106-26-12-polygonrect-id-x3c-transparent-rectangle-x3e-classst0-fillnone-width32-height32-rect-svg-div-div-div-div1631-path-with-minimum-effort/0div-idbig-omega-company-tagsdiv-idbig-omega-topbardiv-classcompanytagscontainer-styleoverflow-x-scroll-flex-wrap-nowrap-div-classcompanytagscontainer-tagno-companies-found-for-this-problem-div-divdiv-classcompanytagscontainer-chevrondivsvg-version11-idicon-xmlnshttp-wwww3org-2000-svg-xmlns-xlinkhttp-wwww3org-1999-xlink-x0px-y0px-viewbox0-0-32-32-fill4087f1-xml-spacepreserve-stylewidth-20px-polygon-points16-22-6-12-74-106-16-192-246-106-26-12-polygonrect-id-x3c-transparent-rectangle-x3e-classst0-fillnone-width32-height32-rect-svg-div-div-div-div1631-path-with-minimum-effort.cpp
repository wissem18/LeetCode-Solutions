class Solution {
public:
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int MOD = 1e9 + 7;
int minimumEffortPath(vector<vector<int>> &heights) {
    int n=heights.size();
    int m=heights[0].size();
    vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        int effort = pq.top().first;
        int x = pq.top().second / m, y = pq.top().second % m;
        pq.pop();

        if (x == n - 1 && y == m - 1) return effort;
        if (effort >= efforts[x][y]) continue;
        efforts[x][y] = effort;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int newEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));
            pq.push({newEffort, nx * m + ny});
        }
    }
    return 0;
}
};