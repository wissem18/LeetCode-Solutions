class Solution {
public:
int equalPairs(vector<vector<int>>& grid) {
    int n=grid.size();
    int ans=0;
    for (int i = 0; i < n; ++i) {
       
        for (int j = 0; j < n; ++j) {
            bool test=true;
            for (int k = 0; k < n; ++k) {
                if(grid[k][j]!=grid[i][k]){
                    test=false;
                    break;
                }
            }
            if(test)
                ans++;
        }
        
    }
return ans;
}
};