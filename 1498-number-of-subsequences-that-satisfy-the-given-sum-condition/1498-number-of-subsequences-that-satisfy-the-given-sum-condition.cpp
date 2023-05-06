class Solution {
public:
int MOD = 1e9+7;
int binpow(long long a, int b, int m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a )% m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int numSubseq(vector<int>& nums, int target) {
sort(nums.begin(),nums.end());
int ans=0;
int n= nums.size();
    for (int i = 0; i <n ; ++i) {
       int x= upper_bound(nums.begin(),nums.end(),target-nums[i])-nums.begin()-1;
        if(x<i)
            break;
        ans=(ans+ binpow(2,x-i,MOD))%MOD;
    }
    return ans;
}
};