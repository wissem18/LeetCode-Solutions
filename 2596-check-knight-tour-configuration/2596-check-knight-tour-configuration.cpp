class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
    int n=grid.size();
    int dx[] = {2,2,1,1,-2,-2,-1,-1};
    int dy[] = {1,-1,2,-2,1,-1,2,-2};
    pair<int,int>pos={0,0};
    if(grid[0][0]!=0)
        return false;
    for (int i = 1; i < n*n; ++i) {
        bool test=false;
        for (int j = 0; j < 8; ++j) {
            if(pos.first+dx[j]>=0&&pos.first+dx[j]<n&&pos.second+dy[j]>=0&&pos.second+dy[j]<n&&grid[pos.first+dx[j]][pos.second+dy[j]]==i){
                pos.first=pos.first+dx[j];
                pos.second=pos.second+dy[j];
                test=true;
                break;
            }
        }
        if(!test)
            return false;
    }
    return true;
}
};