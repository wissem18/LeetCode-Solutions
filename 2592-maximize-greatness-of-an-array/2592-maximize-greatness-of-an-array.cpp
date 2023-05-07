class Solution {
public:

int maximizeGreatness(vector<int>& nums) {
sort(nums.begin(),nums.end());
int ind=0;
int ans=0;
    for (int i = 0; i < nums.size(); ++i) {
        ind= max(ind+1,int(upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin()));
        if(ind<nums.size())
            ans++;
        if(ind>=nums.size()-1)
            break;
    }
    return ans;
}
};