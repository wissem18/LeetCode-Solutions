class Solution {
public:
int MOD = 1e9 + 7;
vector<int>mem;
int dp(int i,int k,string &s){
    if(i==s.size()){
        return 1;
    }
    if(s[i]=='0')
    return 0;
    if(mem[i]!=-1)
    return mem[i];
    int ans=0;
    long long cur=0;
    for(int j=i;j<s.size();j++){
        cur=cur*10+s[j]-'0';
        if(cur>k)
        break;
        ans=(ans+dp(j+1,k,s))%MOD;
        }
    return mem[i]=ans;
}
int numberOfArrays(string s, int k) {
    int n=s.size();
    mem.assign(n,-1); 
    return dp(0,k,s);
}
};