class Solution {
public:
 vector<int> findColumnWidth(vector<vector<int>>& grid) {
int n=grid.size();
int m=grid[0].size();
vector<int>ans(m);
    for (int i = 0; i < m; ++i) {
        ans[i]=0;
        for (int j = 0; j < n; ++j) {
            if(grid[j][i]>=0){
                string x= to_string(grid[j][i]);
                ans[i]=max(ans[i],(int)x.size());
            }
            else{
                string x= to_string(-grid[j][i]);
                ans[i]=max(ans[i],(int)x.size()+1);
            }
        }
    }
    return ans;
}
};