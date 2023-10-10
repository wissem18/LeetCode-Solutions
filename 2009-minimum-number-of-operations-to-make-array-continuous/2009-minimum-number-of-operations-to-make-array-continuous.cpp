class Solution {
public:
int minOperations(vector<int>& nums) {
int n=nums.size();
sort(nums.begin(),nums.end());
vector<int> duplcount(n+1,0);
    for (int i = 1; i < n; ++i) {
        duplcount[i+1]=duplcount[i]+(nums[i]==nums[i-1]);
    }
int ans=1e9;
    for (int i = 0; i < nums.size(); ++i) {
        int x= upper_bound(nums.begin(),nums.end(),nums[i]+n-1)-nums.begin();
        x--;
        ans=min(ans,n-x+i-1+duplcount[x+1]-duplcount[i]);
    }
    return ans;
}

};