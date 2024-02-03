class Solution {
public:
long long maximumSubarraySum(vector<int>& nums, int k) {
map<int,vector<int>>occ;
int n=nums.size();
    for (int i = 0; i < n; ++i) {
        occ[nums[i]].push_back(i);
    }
    vector<long long>pre(n+1,0);
    for (int i = 0; i < n; ++i) {
        pre[i+1]=pre[i]+nums[i];
    }
    long long ans=LONG_LONG_MIN;
    for (int i = 0; i < n; ++i) {
        for (auto x:occ[nums[i]+k]) {
            int j=i;
            if(x<j)swap(x,j);
            ans=max(ans,pre[x+1]-pre[j]);
        }
    }
        if(ans==LONG_LONG_MIN)
        return 0;
    return ans;
}
};