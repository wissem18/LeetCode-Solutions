class Solution {
public:
int numIdenticalPairs(vector<int>& nums) {
int n= nums.size();
vector<int>occ(101,0);
    for (int i = 0; i < n; ++i) {
        occ[nums[i]]++;
    }
    int ans=0;
    for (int i = 1; i <=100 ; ++i) {
     ans+=occ[i]*(occ[i]-1)/2;
    }
    return ans;
}
};