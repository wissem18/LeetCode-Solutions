class Solution {
public:
    vector<int> dx = { 0, 0, -1, -1, -1, 1, 1, 1 };//we write all the possible moves in the problem
vector<int> dy = { -1, 1, 0, -1, 1, -1, 1, 0 };
int n;
bool canMove(int i,int j){
    return (i>=0&&i<n&&j>=0&&j<n);
}
vector<vector<bool>>vis;
int bfs(int pi,int pj,vector<vector<int>>&grid){
    vis[pi][pj]=true;
    queue<pair<int,int>> qi;
    queue<int> qj;
    qi.push({pi,1});
    qj.push(pj);
    int ans=0;
    while(!qi.empty()){
        pair<int,int> x=qi.front();
        qi.pop();
        int y=qj.front();
        qj.pop();
        ans=x.second;
        if(x.first==n-1&&y==n-1)
            break;
        for (int k = 0; k < 8; ++k) {
            int i=x.first+dx[k];
            int j=y+dy[k];
            if(!canMove(i,j)|| grid[i][j])
                continue;
            if(!vis[i][j]){
                qi.push({i,x.second+1});
                qj.push(j);
                vis[i][j]=true;
            }
        }
    }
    return ans;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
n=grid.size();
if(!grid[0][0]){
    vis.assign(n,vector<bool>(n,false));
    int x= bfs(0,0,grid);
    if(vis[n-1][n-1])
        return x;
    else
        return -1;
}
else return -1;
}
};