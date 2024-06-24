class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int cur= 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k && nums[i - k] == 2) {
                cur--;
            }

            // Check if the current bit needs to be flipped
            if ((cur % 2) == nums[i]) {
                // If flipping would exceed array bounds, return -1
                if (i + k > nums.size()) {
                    return -1;
                }
                // Mark the current bit as flipped
                nums[i] = 2;
                cur++;
                ans++;
            }
        }

        return ans;  
    }
};