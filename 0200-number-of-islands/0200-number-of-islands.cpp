class Solution {
public:
vector<vector<bool>>vis;
vector<int> dx = {0, 1, 0, -1} ;
vector<int> dy = {1, 0, -1, 0} ;    
void dfs(int x,int y,vector<vector<char>>& grid){
    vis[x][y]=true;
    for (int i = 0; i < 4; ++i) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||ny<0||nx>=grid.size()||ny>=grid[0].size()||grid[nx][ny]=='0'||vis[nx][ny])
            continue;
        dfs(nx,ny,grid);
    }
}
int numIslands(vector<vector<char>>& grid) {
int n=grid.size();
int m=grid[0].size();
vis.assign(n,vector<bool>(m,false));
int ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(grid[i][j]=='1'&&!vis[i][j]){
                ans++;
                dfs(i,j,grid);
            }
        }
    }
    return ans;
}
};