class Solution {
public:
  vector<  int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
    vector<vector<int>> generateMatrix  (int n) {
vector<vector<int>>ans(n,vector<int>(n, false));;
vector<vector<bool>>vis(n,vector<bool>(n, false));
    int x=0,y=0,dir=0;
    for (int i = 1; i <=n*n; ++i) {
       ans[x][y]=i;
        vis[x][y]=true;
        int newx=x+dx[dir];
        int newy=y+dy[dir];
        if(newx>=0&&newx<n&&newy>=0&&newy<n&&!vis[newx][newy]){
            x=newx;
            y=newy;
        }
        else{
            dir=(dir+1)%4;
            x=x+dx[dir];
            y=y+dy[dir];
        }
    }
    return ans;
}
};