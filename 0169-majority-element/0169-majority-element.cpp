class Solution {
public:
int majorityElement(vector<int> &nums) {
unordered_map<int,int>occ;
int n=nums.size();
    for (int i = 0; i < n; ++i) {
        occ[nums[i]]++;
        if(occ[nums[i]]>n/2)
            return nums[i];
    }
    return  0;
}
};