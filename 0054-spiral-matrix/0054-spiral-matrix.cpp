class Solution {
public:
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
vector<int> spiralOrder(vector<vector<int>>& matrix) {
int n=matrix.size();
int m=matrix[0].size();
vector<int>ans;
vector<vector<bool>>vis(n,vector<bool>(m, false));
    int x=0,y=0,dir=0;
    for (int i = 0; i < m*n; ++i) {
        ans.push_back(matrix[x][y]);
        vis[x][y]=true;
        int newx=x+dx[dir];
        int newy=y+dy[dir];
        if(newx>=0&&newx<n&&newy>=0&&newy<m&&!vis[newx][newy]){
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