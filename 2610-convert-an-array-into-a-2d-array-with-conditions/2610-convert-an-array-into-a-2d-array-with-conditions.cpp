class Solution {
public:
vector<vector<int>> findMatrix(vector<int>& nums) {
    int n=nums.size();
vector<int>occ(n+1,0);
    for (int i = 0; i < n; ++i) {
        occ[nums[i]]++;
    }
    int mx=*max_element(occ.begin(),occ.end());
    vector<vector<int>>ans(mx);
    for (int i = 1; i <=n ; ++i) {
        for (int j = 0; j < occ[i]; ++j) {
            ans[j].push_back(i);
        }
    }
    return ans;
}
};