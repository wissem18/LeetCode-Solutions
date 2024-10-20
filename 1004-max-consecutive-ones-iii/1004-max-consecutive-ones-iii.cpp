class Solution {
public:

int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();
    int i = 0, j = 0;
    int cnt = 0;
    int ans = 0;
    while (i<n && j < n) {
        while (j < n && cnt <= k) {
            if (!nums[j])
                cnt++;
            j++;
        }
        if(cnt>k){
            j--;
            cnt--;
        }
        ans = max(ans, j - i);
        if (!nums[i])
            cnt--;
        i++;
    }
    return ans;
}
};