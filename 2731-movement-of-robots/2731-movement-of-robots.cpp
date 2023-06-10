class Solution {
public:
int MOD=1000000007;
int sumDistance(vector<int>& nums, string s, int d) {
vector<long long>a;
int n=nums.size();
    for (int i = 0; i < n; ++i) {
        if(s[i]=='R'){
            a.push_back(nums[i]+d);
        }
        else{
            a.push_back(nums[i]-d);
        }
    }
    sort(a.rbegin(),a.rend());
    int ans=0;
    for (int i = 0; i < n; ++i) {
        ans=(ans%MOD+(a[i]*1LL*(n-2*i-1))%MOD+MOD)%MOD;
    }
    
    return ans;
}
};