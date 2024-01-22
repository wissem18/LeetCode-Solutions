class Solution {
public:
vector<int> findErrorNums(vector<int> &nums) {
    int n=nums.size();
   vector<int>occ(n+1,0);
   vector<int>ans;
    for (int i = 0; i < n; ++i) {
        occ[nums[i]]++;
        if(occ[nums[i]]==2)
            ans.push_back(nums[i]);
    }
    for (int i = 1; i <=n ; ++i) {
        if(!occ[i])
            ans.push_back(i);
    }
    return ans;
}
};