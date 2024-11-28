class Solution {
public:
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};

int minimumObstacles(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));
    minObstacles[0][0] = grid[0][0];
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({minObstacles[0][0], 0, 0});

    while (!pq.empty()) {
        vector<int> current = pq.top();
        pq.pop();
        int obstacles = current[0], row = current[1], col = current[2];
        if (row == m - 1 && col == n - 1) {
            return obstacles;
        }
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i], newCol = col + dy[i];

            if (newRow >= 0 && newCol >= 0 && newRow < grid.size() &&
                newCol < grid[0].size()) {
                int newObstacles = obstacles + grid[newRow][newCol];

                if (newObstacles < minObstacles[newRow][newCol]) {
                    minObstacles[newRow][newCol] = newObstacles;
                    pq.push({newObstacles, newRow, newCol});
                }
            }
        }
    }

    return minObstacles[m - 1][n - 1];
}
};