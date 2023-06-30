class Solution {
public:
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int MOD = 1e9 + 7;
bool verify(int &mid, int &row, int &col, vector<vector<int>> &cells) {
    vector<vector<int>> a(row, vector<int>(col, 0));
    for (int i = 0; i < mid; ++i) {
        a[cells[i][0] - 1][cells[i][1] - 1] = 1;
    }
    queue<pair<int,int>>q;
    for (int i = 0; i < col; ++i) {
        if(!a[0][i]){
            q.push({0,i});
            a[0][i]=1;
        }
    }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==row-1)
            return true;
        for (int i = 0; i < 4; ++i) {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||nx>=row||ny<0||ny>=col||a[nx][ny])
                continue;
            a[nx][ny]=1;
            q.push({nx,ny});
        }
    }
    return false;
}
int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
    int n = cells.size();
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r+1) / 2;
        if (verify(mid, row, col, cells)) {
            l = mid ;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
};