class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>res;
    map<int,int>index;
    for (int i = 0; i < nums.size(); ++i) {
        index[nums[i]]=i;
    }
    for(int i=0;i<nums.size();i++){
        if(index.count(target-nums[i])&&i!=index[target-nums[i]]){
            res.push_back(i);
            res.push_back(index[target-nums[i]]);
            break;
        }
    }
    return res;
}
};