class Solution {
public:
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

vector<vector<bool>>vis;
pair<int,int> mn,mx;
void dfs(int x,int y,vector<vector<int>>& grid){
    vis[x][y]=true;
    mn=min(mn,{x,y});
    mx=max(mx,{x,y});
    for (int i = 0; i < 4; ++i) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||ny<0||nx>=grid.size()||ny>=grid[0].size()||!grid[nx][ny]||vis[nx][ny])
            continue;
        dfs(nx,ny,grid);
    }
}
vector<vector<int>> findFarmland(vector<vector<int>>& land) {
int n=land.size();
int m=land[0].size();
vis.assign(n,vector<bool>(m,false));
vector<vector<int>> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(land[i][j]==1&&!vis[i][j]){
                mn={n,m},mx={0,0};
                dfs(i,j,land);
                ans.push_back({mn.first,mn.second,mx.first,mx.second});
            }
        }
    }
    return ans;
}
};