class Solution {
public:
int longestSubarray(vector<int> &nums, int limit) {
    int n = nums.size();
    multiset<int> s;
    int ans = 0;
    int l = 0, r = 0;
    int mn = 0, mx = 0;
    while (r < n) {
      s.insert(nums[r]);
      mn = *s.begin();
      mx = *prev(s.end());
      while (mx - mn > limit) {
        s.erase(s.find(nums[l]));
        l++;
        mn = *s.begin();
        mx = *prev(s.end());
    }
      ans=max(ans,r-l+1);
      r++;
    }
    return ans;
}
};