class Solution {
public:
vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
int n=grid.size();
int m=grid[0].size();
map<int,int>mp;
    for (int i = 0; i < n; ++i) {
        int cnt=0;
        for (int j = 0; j < m; ++j) {
            if(grid[i][j]){
                cnt+=(1<<j);
            }
        }
        if(cnt==0)
            return{i};
        mp[cnt]=i;
        for (int j = 1; j < (1<<m); ++j) {
            if(!(cnt&j)&&mp.count(j)){
                return {mp[j],i};
            }
        }
    }
    return {};
}
};