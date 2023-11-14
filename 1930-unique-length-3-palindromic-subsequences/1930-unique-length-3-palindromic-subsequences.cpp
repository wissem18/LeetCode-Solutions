class Solution {
public:
int countPalindromicSubsequence(string s) {
int n=s.size();
vector<int>first(26,-1),last(26,-1);
vector<vector<int>>pre(26,vector<int>(n+1,0));
    for (int i = 0; i < n; ++i) {
        int cur=s[i]-'a';
        last[cur]=i;
        if(first[cur]==-1)
            first[cur]=i;
        for (int j = 0; j <26 ; ++j) {
            pre[j][i+1]=pre[j][i]+(cur==j);
        }
    }
    int ans=0;
    for (int i = 0; i < 26; ++i) {
        if(first[i]==last[i]||first[i]==-1)continue;
        int cnt=0;
        int r=last[i]-1;
        int l=first[i]+1;
        if(l>r)continue;
        for (int j = 0; j < 26; ++j) {
            cnt+=(pre[j][r+1]-pre[j][l])>0;
        }
        ans+=cnt;
    }
    return ans;
}
};