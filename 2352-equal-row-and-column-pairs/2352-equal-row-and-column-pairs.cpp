class Solution {
public:
int equalPairs(vector<vector<int>>& grid) {
    int n=grid.size();
    map<vector<int>,int>cnt;
    for (auto x:grid) {
        cnt[x]++;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            swap(grid[i][j],grid[j][i]);
        }
    }
    int ans=0;
    for (auto x:grid) {
     ans+=cnt[x];
    }
return ans;
}
};