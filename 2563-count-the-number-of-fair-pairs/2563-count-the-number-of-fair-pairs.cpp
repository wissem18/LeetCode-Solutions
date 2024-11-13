class Solution {
public:
int findValidPairs(int upper, vector<int> &nums) {
    auto it = upper_bound(nums.begin(), nums.end(), upper);
    if (it == nums.begin())
        return 0;
    return it - nums.begin();
}

long long countFairPairs(vector<int> &nums, int lower, int upper) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
     ans+= findValidPairs(upper-nums[i],nums)- findValidPairs(lower-1-nums[i],nums);
     //treat the case of counting the pairs of same index
     if(nums[i]*2>=lower&&nums[i]*2<=upper)
         ans-=1;
    }
    return ans/2;
}
};