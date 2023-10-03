class Solution {
public:
int numIdenticalPairs(vector<int>& nums) {
int n= nums.size();
unordered_map<int,int>occ;
    for (int i = 0; i < n; ++i) {
        occ[nums[i]]++;
    }
    int ans=0;
    for (auto x:occ) {
        ans+=x.second*(x.second-1)/2;
    }
    return ans;
}
};