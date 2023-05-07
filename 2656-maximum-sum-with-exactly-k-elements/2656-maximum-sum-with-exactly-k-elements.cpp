class Solution {
public:
int maximizeSum(vector<int>& nums, int k) {
int mx=*max_element(nums.begin(),nums.end());
int ans=(2*mx+k-1)*k/2;
return ans;
}
};