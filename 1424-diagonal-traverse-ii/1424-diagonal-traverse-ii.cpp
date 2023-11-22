class Solution {
public:
vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int n=nums.size();
    int m=0;
    for (int i = 0; i < n; ++i) {
        m=max(int(nums[i].size()),m);
    }
vector<vector<int>>a(n+m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < nums[i].size(); ++j) {
            a[i+j].push_back(nums[i][j]);
        }
    }
    vector<int>ans;
    for (int i = 0; i < n+m; ++i) {
        for (int j = a[i].size()-1; j >=0 ; --j) {
            ans.push_back(a[i][j]);
        }
    }
    return ans;
}
};