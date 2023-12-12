class Solution {
public:
int maxProduct(vector<int>& nums) {
int mx=max_element(nums.begin(),nums.end())-nums.begin();
int smx=0;
    for (int i = 0; i < nums.size(); ++i) {
        if(i==mx)continue;
        smx= max(smx,nums[i]);
    }
    return (nums[mx]-1)*(smx-1);
}
};