class Solution {
public:
    int MOD = 1e9+7;
int first[5]={	10, 20, 46, 104, 240};
vector<int>mem;
int dp(int i){
    if(i<5)
        return first[i];
    if(mem[i]!=-1)
        return mem[i];
    return mem[i]=(((6LL*dp(i-2))%MOD-4LL*dp(i-4))%MOD+MOD)%MOD;
}
int knightDialer(int n) {
mem.assign(n,-1);
return dp(n-1);
}
};