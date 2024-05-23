class Solution {
public:
    int dp(vector<int>& nums, int difference, unordered_map<int, int>& freqMap, int i) {
        // Base case: Return 1 for a subset of size 1
        if (i == nums.size()) {
            return 1;
        }
        // Count subsets where nums[i] is not taken
        int ans = dp(nums, difference, freqMap,i + 1); // nums[i] not taken

        // If nums[i] can be taken without violating the condition
        if (!freqMap[nums[i] - difference]) {
            freqMap[nums[i]]++;
            // Recursively count subsets where nums[i] is taken
            ans += dp(nums, difference, freqMap,
                                                i + 1); // nums[i] taken
            freqMap[nums[i]]--;
        }

        return ans;
    }
int beautifulSubsets(vector<int>& nums, int k) {
   // Frequency map to track elements
        unordered_map<int, int> freqMap;
        // Sort nums array
        sort(nums.begin(), nums.end());
        return dp(nums, k, freqMap, 0) - 1;
}
};