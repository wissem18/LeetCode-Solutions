class Solution {
public:
int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int x= lower_bound(grid[i].rbegin(),grid[i].rend(),0)-grid[i].rbegin();
            cnt+=x;
        }
        return cnt;
    }
};