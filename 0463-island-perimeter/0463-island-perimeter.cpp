class Solution {
public:
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
int islandPerimeter(vector<vector<int>>& grid) {
int n=grid.size();
int m=grid[0].size();
int ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(grid[i][j]==1){
                for (int k = 0; k < 4; ++k) {
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni<0||ni>=n||nj<0||nj>=m||grid[ni][nj]==0)
                        ans++;
                }
            }
        }
    }
    return ans;
}
};