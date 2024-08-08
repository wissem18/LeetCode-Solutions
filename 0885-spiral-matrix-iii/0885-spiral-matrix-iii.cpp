class Solution {
public:
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> ans;
    int step = 1, dir = 0;
    while (ans.size() < rows * cols) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < step; ++j) {
                if (rStart >= 0 && rStart < rows && cStart >= 0 &&
                    cStart < cols) {
                    ans.push_back({rStart, cStart});
                }
                rStart += dx[dir];
                cStart += dy[dir];
            }
            dir = (dir + 1) % 4;
        }
        step++;
    }
    return ans;

}
};