class Solution {
public:
int minFlipsMonoIncr(string s) {
int n=s.size();
int pre0[n+1];
pre0[0]=0;
    for (int i = 0; i < n; ++i) {
        pre0[i+1]=pre0[i]+(s[i]=='0');
    }
int ans=INT_MAX;
    for (int i = 0; i < n; ++i) {
        int x=i-pre0[i]+pre0[n]-pre0[i];
        ans=min(ans,x);
    }
    int c=n-pre0[n];
    ans=min(ans,c);
    return ans;
}

};