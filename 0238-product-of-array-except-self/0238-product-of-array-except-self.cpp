class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int>ans(n);
    vector<int>occ(61,0);
    for (int i = 0; i < n; ++i) {
        occ[nums[i]+30]++;
    }
    for (int i = 0; i < n; ++i) {
        occ[nums[i]+30]--;
        long long cur=1;
        for (int j = 0; j <=60 ; ++j) {
            cur*=pow((j-30)*1LL,occ[j]);
        }
        ans[i]=cur;
        occ[nums[i]+30]++;
    }
    return ans;
}
};