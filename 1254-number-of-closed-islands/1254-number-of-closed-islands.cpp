class Solution {
public:
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};
vector<vector<bool>>vis;
int n,m;
bool canMove(int i,int j){
    return (i>=0&&i<n&&j>=0&&j<m);
}
bool bfs(int pi,int pj,vector<vector<int>>& grid){
    vis[pi][pj]=true;
    queue<int> qi;
    queue<int> qj;
    qi.push(pi);
    qj.push(pj);
    bool test=true;
    while(!qi.empty()){
        int x=qi.front();
        qi.pop();
        int y=qj.front();
        qj.pop();

        for (int k = 0; k <4; ++k) {
            int i=x+dx[k];
            int j=y+dy[k];
            if(!canMove(i,j))
            {
                test=false;
                continue;
            }
            if(!vis[i][j]&&grid[i][j]!=1){
                qi.push(i);
                qj.push(j);
                vis[i][j]=true;
            }
        }
    }
    return test;
}
int closedIsland(vector<vector<int>>& grid) {
 n=grid.size();
 m=grid[0].size();
vis.assign(n,vector<bool>(m,false));
int ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
         if(!grid[i][j]&&!vis[i][j]){
          ans+=bfs(i,j,grid);
         }
        }
    }
    return ans;
}
};