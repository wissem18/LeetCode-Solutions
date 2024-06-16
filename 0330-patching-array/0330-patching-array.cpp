class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long missing = 1;
        int ans = 0;
        int i = 0;

        while (missing <= n) {
            if (i < nums.size() && nums[i] <= missing) {
                missing += nums[i];
                i++;
            } else {
                missing += missing;
                ans++;
            }
        }

        return ans;
    }
};