class Solution {
public:
int subset(int i,int cur,vector<int> &nums){
    if(i==nums.size())
        return cur;
    return subset(i+1,cur^nums[i],nums)+subset(i+1,cur,nums);
}
int subsetXORSum(vector<int> &nums) {
 return subset(0,0,nums);

}
};