class Solution {
public:
int maxDistance(vector<vector<int>>& grid) {
int n=grid.size();
vector<pair<int,int>>p0,p1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(grid[i][j])
                p1.push_back({i,j});
            else
                p0.push_back({i,j});
        }
    }
    if(p0.empty()||p1.empty())
        return -1;
    int ans=0;
    for (auto a:p0) {
        int mn=1e9;
        for (auto b:p1) {
            mn=min(mn,abs(a.first-b.first)+abs(a.second-b.second));
        }
        ans=max(ans,mn);
    }
    return ans;
}
};