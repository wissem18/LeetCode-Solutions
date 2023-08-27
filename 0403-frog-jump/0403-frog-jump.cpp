class Solution {
public:
    int n;
vector<vector<int>>mem;
map<int,int>ind;
bool dp(int i,int prev,vector<int>& stones){
    if(i== n-1)
        return true;
    if(mem[i][prev]!=-1)
        return mem[i][prev];
    bool ans=false;
    for (int j = prev-1; j <=prev+1 ; ++j) {
        if(j>0&&ind.count(stones[i]+j)){
            ans|=dp(ind[stones[i]+j],j,stones);
        }
    }
return mem[i][prev]=ans;

}
bool canCross(vector<int>& stones) {
n=stones.size();
mem.assign(n,vector<int>(n+1,-1));
    for (int i = 0; i < n; ++i) {
        ind[stones[i]]=i;
    }
    return dp(0,0,stones);
}
};