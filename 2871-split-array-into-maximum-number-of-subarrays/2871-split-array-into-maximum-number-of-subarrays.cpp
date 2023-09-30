class Solution {
public:

int maxSubarrays(vector<int>& nums) {
int n=nums.size();
int ans=1;
int cur=(1<<30)-1;
    for (int i = 0; i < n; ++i) {
        cur&=nums[i];
        if(!cur&&i!=n-1){
            ans++;
            cur=(1<<30)-1;
        }
    }
    if(cur>0&&ans>1)
        ans--;
    return ans;
}
};