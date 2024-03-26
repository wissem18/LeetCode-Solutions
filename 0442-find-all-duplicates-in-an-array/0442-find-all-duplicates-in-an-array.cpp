class Solution {
public:
vector<int> findDuplicates(vector<int>& nums) {
unordered_map<int,int>occ;
vector<int>ans;
    for (int i = 0; i <nums.size() ; ++i) {
        occ[nums[i]]++;
        if(occ[nums[i]]==2)
            ans.push_back(nums[i]);
    }
    return ans;
}
};