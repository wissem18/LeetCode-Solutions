class Solution {
public:
 vector<vector<int>>mem;
int dp(int left,int right,vector<int>& cuts){
    if(left==right-1)
        return 0;
    if(mem[left][right]!=-1)
        return mem[left][right];
    int ans=INT_MAX;
    for (int i = left+1; i <right ; ++i) {
        int cur=dp(left,i,cuts)+dp(i,right,cuts)+cuts[right]-cuts[left];
        ans=min(ans,cur);
    }
return mem[left][right]=ans;
}
int minCost(int n, vector<int>& cuts) {
cuts.push_back(n);
 cuts.push_back(0);   
sort(cuts.begin(),cuts.end());
int m=cuts.size();
mem.assign(m,vector<int>(m,-1));
return dp(0,m-1,cuts);
}
};