class Solution {
public:
    
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
int n=mat.size();
int m=mat[0].size();
queue<pair<int,int>>q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(mat[i][j])
                mat[i][j]=-1;
            else
                q.push({i,j});
        }
    }
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||mat[nx][ny]!=-1)
                continue;
            mat[nx][ny]=mat[x][y]+1;
            q.push({nx,ny});
        }
    }
    return mat;
}
};