class Solution {
public:
int helper(vector<int> &nums, int k){
     int n = nums.size();
    int l = 0, r = 0;
    int cnt = 0;
    int ans = 0;
    while (l < n) {
        while (cnt < k && r < n) {
            cnt += (nums[r] % 2);
            r++;
        }
        if (cnt < k)
            break;
        ans += n - r + 1;
        if (nums[l] % 2)
            cnt--;
        l++;
    }
    return ans;
}    
int numberOfSubarrays(vector<int> &nums, int k) {
   return helper(nums,k)-helper(nums,k+1);
}
};