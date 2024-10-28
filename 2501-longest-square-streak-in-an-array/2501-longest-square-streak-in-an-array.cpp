class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for (int x : nums) {
            int curr = 0;
            long long  current= x;
            while (s.find((int)current) !=s.end()) {
                curr++;
                if (current * current > 1e5) break;

                current *= current;
            }

        
            ans = max(ans, curr);
        }
        return ans< 2 ? -1 : ans;
    }
};