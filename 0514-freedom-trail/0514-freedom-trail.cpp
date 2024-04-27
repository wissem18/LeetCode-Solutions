class Solution {
public:
vector<vector<int>>mem;
int dp(int i,int next,string &ring, string &key){
    if(i==key.size())
        return 0;
    if(mem[i][next]!=-1)
        return mem[i][next];
    int ans=1e9;
    for (int j = 0; j <ring.size() ; ++j) {
        if(ring[j]==key[i]){
            int clockWiseSteps=(ring.size()-(next-j))%ring.size();
            int antiClockWiseSteps=(ring.size()-(j-next))%ring.size();
            ans=min(ans,dp(i+1,j,ring,key)+min(clockWiseSteps,antiClockWiseSteps));
        }
    }
    return mem[i][next]=ans;
}
int findRotateSteps(string ring, string key) {
int n=ring.size();
int m=key.size();
mem.assign(m,vector<int>(n,-1));
return dp(0,0,ring,key)+key.size();
}
};