class Solution {
public:
int maxSubarraySumCircular(vector<int>& nums) {
   if(nums.size()==1)
       return nums[0];
   int sum=0;
    for (int i = 0; i < nums.size(); ++i) {
        sum+=nums[i];
    }
    int curr_min=nums[0],mn=nums[0],curr_max=nums[0],mx=nums[0];
    for (int i = 1; i <nums.size() ; ++i) {
        curr_max=max(curr_max+nums[i],nums[i]);
        mx=max(mx,curr_max);
        curr_min=min(curr_min+nums[i],nums[i]);
        mn=min(mn,curr_min);
    }
    if(mn==sum){//all elements are negative so we return the max element in the array which is equal to mx
        return mx;
         }
    return (max(mx,sum-mn));
}
};