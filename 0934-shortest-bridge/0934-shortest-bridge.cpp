class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
 vector<vector<bool>>vis;
int n;
void dfs(int x,int y,vector<pair<int,int>>&v,vector<vector<int>>& grid){
    vis[x][y]=true;
    v.push_back({x,y});
    for (int i = 0; i < 4; ++i) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!(nx>=0&&ny>=0&&nx<n&&ny<n)){
            continue;
        }
        if(!vis[nx][ny]&&grid[nx][ny]){
            dfs(nx,ny,v,grid);
        }
    }
}
int shortestBridge(vector<vector<int>>& grid) {
n=grid.size();
vis.assign(n,vector<bool>(n,false));
vector<pair<int,int>>i1,i2;
int nb=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(!vis[i][j]&&grid[i][j]){
                if(!nb){
                    nb++;
                    dfs(i,j,i1,grid);
                }
                else{
                    dfs(i,j,i2,grid);
                }
            }
        }
    }
    int ans=1e9;
    for (int i = 0; i < i1.size(); ++i) {
        for (int j = 0; j < i2.size(); ++j) {
            ans=min(ans,abs(i1[i].first-i2[j].first)+abs(i1[i].second-i2[j].second)-1);
        }
    }
    return ans;
}
};