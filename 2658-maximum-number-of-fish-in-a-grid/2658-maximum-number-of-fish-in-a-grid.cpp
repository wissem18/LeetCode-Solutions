class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};
 int n,m;
bool canMove(int i,int j){
    return (i>=0&&i<n&&j>=0&&j<m);
}
vector<vector<bool>>vis;
int bfs(int pi,int pj,vector<vector<int>>& grid){
    vis[pi][pj]=true;
    queue<int> qi;
    queue<int> qj;
    qi.push(pi);
    qj.push(pj);
    int ans=0;
    while(!qi.empty()){
        int x=qi.front();
        qi.pop();
        int y=qj.front();
        qj.pop();
        ans+=grid[x][y];
        for (int i = 0; i < 4; ++i) {
            int ii=x+dx[i];
            int jj=y+dy[i];
            if(!canMove(ii,jj)||!grid[ii][jj])
                continue;
            if(!vis[ii][jj]){
                qi.push(ii);
                qj.push(jj);
                vis[ii][jj]=true;
            }
        }
    }
    return ans;
}
int findMaxFish(vector<vector<int>>& grid) {
 n=grid.size();
 m=grid[0].size();
 vis.resize(n,vector<bool>(m,false));
 int ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(grid[i][j]&&!vis[i][j])
                ans=max(ans,bfs(i,j,grid));
        }
    }
    return ans;
}
};