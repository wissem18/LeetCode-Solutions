class Solution {
public:
 int missingInteger(vector<int>& nums) {
int n=nums.size();
int i=1;
int s=nums[0];
while(i<n&&nums[i]==nums[i-1]+1){
    s+=nums[i];
    i++;
}
    for (int j = s;; ++j) {
        if(std::find(nums.begin(), nums.end(),j)==nums.end())
        return j;
    }
}
};