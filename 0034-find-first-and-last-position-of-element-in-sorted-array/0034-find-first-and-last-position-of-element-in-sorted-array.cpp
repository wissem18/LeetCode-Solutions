class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
int x= lower_bound(nums.begin(),nums.end(),target)-nums.begin();
int y=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
if(x==y)
    return {-1,-1};
else{
    
    return {x,y-1};
}
}
};