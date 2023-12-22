class Solution {
public:
    int maxScore(string s) {
int n=s.size();
vector<int>pre(n+1,0);
    for (int i = 0; i < n; ++i) {
        pre[i+1]=pre[i]+(s[i]=='0');
    }
 int ans=0;
    for (int i = 0; i < n-1; ++i) {
        ans=max(ans,pre[i+1]+(n-i-1-pre[n]+pre[i+1]));
    }    
    return ans;
}
};