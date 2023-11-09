class Solution {
public:
    int MOD=1e9+7;
int countHomogenous(string s) {
int n=s.size();
char cur=s[0];
int cnt=1;
int ans=0;
    for (int i = 1; i < n; ++i) {
        if(s[i]==cur)
            cnt++;
        else{
            ans=(ans+cnt*1LL*(cnt+1)/2)%MOD;
            cnt=1;
            cur=s[i];
        }
    }
    ans=(ans+cnt*1LL*(cnt+1)/2)%MOD;
    return ans;
}
};