class Solution {
public:
int MOD=1e9+7;
vector<int>mem;
int dp(int len,int &zero,int &one,int &low,int &high){
    if(len>high){
        return 0;
    }
    if(mem[len]!=-1)
        return mem[len];
    return mem[len]=(dp(len+zero,zero,one,low,high)%MOD+dp(len+one,zero,one,low,high)%MOD+(len>=low&&len<=high))%MOD;
}
int countGoodStrings(int low, int high, int zero, int one) {
    mem.assign(high+1,-1);
return dp(0,zero,one,low,high);
}
};