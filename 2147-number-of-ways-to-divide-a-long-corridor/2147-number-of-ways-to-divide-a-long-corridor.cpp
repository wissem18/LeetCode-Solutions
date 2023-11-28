class Solution {
public:
int MOD = 1e9+7;
vector<vector<int>>mem;
int dp(int i,int cnt,string &s){
    if(i==s.size())
        return cnt==2;
   if(mem[i][cnt]!=-1)
       return mem[i][cnt];
    int ans=0;
    if(cnt==2){
        if(s[i]=='S')
            ans=dp(i+1,1,s)%MOD;
        else
            ans=(dp(i+1,2,s)%MOD+dp(i+1,0,s)%MOD)%MOD;
    }
    else{
        ans=dp(i+1,cnt+(s[i]=='S'),s)%MOD;
    }
    return mem[i][cnt]=ans;
}
int numberOfWays(string corridor) {
    int n=corridor.size();
    mem.assign(n,vector<int>(3,-1));
return dp(0,0,corridor);
}
};