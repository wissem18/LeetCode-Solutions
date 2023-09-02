class Solution {
public:
    vector<int>mem;
int n;
int dp(int i,string s, vector<string>& dictionary){
if(i==n)
    return 0;
if(mem[i]!=-1)
    return mem[i];
int ans=dp(i+1,s,dictionary)+1;
    for (int j = i; j <n ; ++j) {
        string cur=s.substr(i,j-i+1);
        if(find(dictionary.begin(), dictionary.end(),cur)!=dictionary.end())
            ans=min(ans,dp(j+1,s,dictionary));
    }
    return mem[i]=ans;
}
int minExtraChar(string s, vector<string>& dictionary) {
n=s.size();
mem.assign(n,-1);
return dp(0,s,dictionary);
}
};