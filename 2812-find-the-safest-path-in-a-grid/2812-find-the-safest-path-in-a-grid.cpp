class Solution {
public:
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
int n;
vector<vector<int>> d;
vector<vector<bool>> vis;

int maximumSafenessFactor(vector<vector<int>> &grid) {
    n = grid.size();
    d.resize(n, vector<int>(n));//minimum distance between cell i,j and the nearest cell with value 1
//Apply multi source BFS to generate this matrix
    queue<pair<int, int>> q;
    vis.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j]){
                q.push({i, j});
                vis[i][j]=true;
            }
        }
    }
    int level = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            pair<int, int> cur = q.front();
            q.pop();
            d[cur.first][cur.second] = level;
            for (int i = 0; i < 4; ++i) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx < 0 || nx == n || ny < 0 || ny == n || vis[nx][ny])continue;
                vis[nx][ny]=true;
                q.push({nx, ny});
            }
        }
        level++;
    }
       vis.assign(n, vector<bool>(n, false));
    // Priority queue to prioritize cells with higher safeness factor
    priority_queue<vector<int>> pq;
    // Push starting cell to the priority queue
    pq.push(vector<int>{d[0][0], 0, 0}); // [maximum_safeness_till_now, x-coordinate, y-coordinate]
    vis[0][0] = true; // Mark the source cell as visited

    // BFS to find the path with maximum safeness factor
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        // If reached the destination, return safeness factor
        if (curr[1] == n - 1 && curr[2] == n - 1) {
            return curr[0];
        }

        // Explore neighboring cells
        for (int i = 0; i < 4; i++) {
            int di = dx[i] + curr[1];
            int dj = dy[i] + curr[2];
            if (di >= 0 && di < n && dj >= 0 && dj < n && !vis[di][dj]) {
                // Update safeness factor for the path and mark the cell as visited
                pq.push(vector<int>{min(curr[0], d[di][dj]), di, dj});
                vis[di][dj] = true;
            }
        }
    }

    return -1;
   
}
};