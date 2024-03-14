class Solution {
public:
int numSubarraysWithSum(vector<int> &nums, int goal) {
    map<int, int> occ;
    int ans = 0;
    int cursum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        occ[cursum]++;
        cursum += nums[i];
        ans += occ[cursum - goal];
        
    }
    return ans;
}
};