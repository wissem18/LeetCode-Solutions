class Solution {
public:
vector<vector<int>>mem;
int dp(int i,int curk,int mx,vector<int>& arr,int &k){
    if(i==arr.size())
        return (k-curk)*mx;
    if(mem[i][curk]!=-1)
        return mem[i][curk];
    if(curk==0)
        return mem[i][curk]=k*mx+dp(i+1,k-1,arr[i],arr,k);
    return mem[i][curk]=max((k-curk)*mx+dp(i+1,k-1,arr[i],arr,k),dp(i+1,curk-1,max(mx,arr[i]),arr,k));
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
int n=arr.size();
mem.assign(n+1,vector<int>(k+1,-1));
return dp(0,k,0,arr,k);
}
};