class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
int nb=0;
int ind=0;
    for (int i = 1; i < nums.size(); ++i) {
        if(nums[i-1]>nums[i]){
            nb++;
            ind=i;
        }
    }
    if(nb==1&&nums[0]>=nums[nums.size()-1])
        return nums.size()-ind;
    else if(nb==0)
        return 0;
    else
        return -1;
}
};