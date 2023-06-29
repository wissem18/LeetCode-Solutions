class Solution {
public:
int shortestPathAllKeys(vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<vector<int>> q;
 vector<vector<vector<bool>>>vis(n,vector<vector<bool>>(m,vector<bool>(64,false)));
    int allKeys = 0;
    int startR = -1, startC = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char cell = grid[i][j];
            if (cell >= 'a' && cell <= 'f') {
                allKeys |= (1 << (cell - 'a'));
            }
            if (cell == '@') {
                startR = i;
                startC = j;
            }
        }
    }

    vis[startR][startC][0];
    q.push({startR, startC, 0, 0});
    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        int curR = cur[0], curC = cur[1], keys = cur[2], dist = cur[3];
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (pair<int, int> dir : directions) {
            int newR = curR + dir.first;
            int newC = curC + dir.second;

            if (newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] != '#') {
                char cell = grid[newR][newC];

                if (cell>='a'&&cell<='f' && !(keys & (1 << (cell - 'a')))) {
                    int newKeys = keys | (1 << (cell - 'a'));

                    if (newKeys == allKeys) {
                        return dist + 1;
                    }

                    if (!vis[newR][newC][newKeys]) {
                        vis[newR][newC][newKeys]=true;
                        q.push({newR, newC, newKeys, dist + 1});
                    }
                } else if (cell>='A'&&cell<='F' && !(keys & (1 << (cell - 'A')))) {
                    continue;
                } else if (!vis[newR][newC][keys]) {
                    vis[newR][newC][keys]=true;
                    q.push({newR, newC, keys, dist + 1});
                }
            }
        }
    }
    return -1;
}
};