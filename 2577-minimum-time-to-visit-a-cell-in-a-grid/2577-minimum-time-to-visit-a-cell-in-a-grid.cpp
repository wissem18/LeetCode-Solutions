class Solution {
public:
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};    
int minimumTime(vector<vector<int>> &grid) {

    if (grid[0][1] > 1 && grid[1][0] > 1) {
        return -1;
    }

    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    pq.push({grid[0][0], 0, 0});

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        int time = curr[0], row = curr[1], col = curr[2];
        if (row == n - 1 && col == m - 1) {
            return time;
        }
        if (vis[row][col]) {
            continue;
        }
        vis[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int nextRow = row + dx[i], nextCol = col + dy[i];
            if (nextRow >= 0 && nextCol >= 0 && nextRow < n &&
                nextCol < m && !vis[nextRow][nextCol]) {
                int waitTime =((grid[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0;
                int nextTime = max(grid[nextRow][nextCol] + waitTime, time + 1);
                pq.push({nextTime, nextRow, nextCol});
            }
        }
    }
    return -1;
}
    
};