class Solution {
public:

void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (nums[i] != 0) {
            int j = i;
            while (j-1 >= 0 && !nums[j-1]) {
                swap(nums[j], nums[j-1]);
                j--;
            }
        }
    }
}
};