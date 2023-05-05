class Solution {
public:
    int maxVowels(string s, int k) {
string v="aeuio";
int n=s.size();
vector<int>pre(n+1,0);
    for (int i = 0; i <n ; ++i) {
        if(v.find(s[i])!=string ::npos){
            pre[i+1]=pre[i]+1;
        }
        else
            pre[i+1]=pre[i];
    }
    int mx=0;
    for (int i = 0; i <= n-k; ++i) {
        mx=max(mx,pre[k+i]-pre[i]);
    }
    return mx;
}
};