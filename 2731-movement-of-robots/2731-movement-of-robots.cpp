class Solution {
public:
int MOD=1000000007;
int sumDistance(vector<int>& nums, string s, int d) {
int n=nums.size();
    for (int i = 0; i < n; ++i) {
        if(s[i]=='R'){
          nums[i]=nums[i]+d;
        }
        else{
            nums[i]=nums[i]-d;
        }
    }
    sort(nums.rbegin(),nums.rend());
    int ans=0;
    for (int i = 0; i < n; ++i) {
        ans=(ans%MOD+(nums[i]*1LL*(n-2*i-1))%MOD+MOD)%MOD;
    }
    
    return ans;
}
};