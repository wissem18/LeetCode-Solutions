class Solution {
public:
int MOD = 1e9 + 7;
long long mem[105][105];

long long dp(int i, int j, int &k,int &n) {
    if (i == 0 || j == 0)
        return (i == 0 && j == 0);
    if(mem[i][j]!=-1)
        return mem[i][j];
    mem[i][j]=(dp(i-1,j-1,k,n)*1LL*(n-j+1))%MOD;
    if(j>k){
        mem[i][j]=(mem[i][j]+dp(i-1,j,k,n)*(j-k))%MOD;
    }
return mem[i][j];
}

int numMusicPlaylists(int n, int goal, int k) {
    memset(mem,-1,sizeof mem);
    return dp(goal,n,k,n);
}
};