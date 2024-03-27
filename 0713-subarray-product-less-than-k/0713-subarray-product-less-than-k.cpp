class Solution {
public:
int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int n = nums.size();
    int l = 0, r = 0;
    int cur = 1;
    int ans = 0;
    while (r < n) {
        cur *= nums[r];
        if(cur<k){
            ans+=(r-l+1);
        }
        else{
            while(l<=r&&cur>=k){ 
                cur/=nums[l];
                l++;
            }
            ans+=(r-l+1);
        }
        r++;
    }
    return ans;
}
};