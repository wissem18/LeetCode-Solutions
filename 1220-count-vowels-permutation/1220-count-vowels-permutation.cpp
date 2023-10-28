class Solution {
public:
int MOD = 1e9 + 7;
vector<vector<int>>mem;
long long dp(int i, int last, int &n) {
    if (i == n)
        return 1;
if(mem[i][last]!=-1)
    return mem[i][last];
    long long ans = 0;
    if (i == 0) {

        for (int j = 0; j < 5; ++j) {
            ans = (ans + dp(i + 1, j, n)) % MOD;
        }
    } else {
        switch (last) {
            case 0 : ans=(ans+dp(i+1,1,n))%MOD;
                break;
            case 1 : ans=(ans+dp(i+1,0,n)+dp(i+1,2,n))%MOD;
                break;
            case 2:  ans=(ans+dp(i+1,0,n)+dp(i+1,1,n)+dp(i+1,3,n)+dp(i+1,4,n))%MOD;
                break;
            case 3 : ans=(ans+dp(i+1,2,n)+dp(i+1,4,n))%MOD;
                break;
            case 4 : ans=(ans+dp(i+1,0,n))%MOD;
        }
    }
    return mem[i][last]=ans;
}

int countVowelPermutation(int n) {
    mem.assign(n,vector<int>(5,-1));
return dp(0,0,n);
}
};