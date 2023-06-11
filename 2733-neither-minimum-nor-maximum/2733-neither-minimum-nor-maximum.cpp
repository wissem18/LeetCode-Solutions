class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
    int n=nums.size();
int mn=*min_element(nums.begin(),nums.end());
int mx=*max_element(nums.begin(),nums.end());
    for (int i = 0; i < n; ++i) {
        if(nums[i]!=mn&&nums[i]!=mx){
            return nums[i];
        }
    }
    return -1;
}
};