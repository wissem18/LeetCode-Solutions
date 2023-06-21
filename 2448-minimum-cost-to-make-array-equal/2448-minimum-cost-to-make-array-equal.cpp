class Solution {
public:
long long minCost(vector<int>& nums, vector<int>& cost) {
vector<pair<int,int>>a;
int n=nums.size();
    for (int i = 0; i < n; ++i) {
        a.push_back({nums[i],cost[i]});
    }
    sort(a.begin(),a.end());
    vector<long long>pre(n+1,0),prec(n+1,0);
    for (int i = 1; i <=n ; ++i) {
        pre[i]=pre[i-1]+a[i-1].second;
        prec[i]=prec[i-1]+a[i-1].first*1LL*a[i-1].second;
    }
    long long ans=1e18;
    for (int i = 0; i < n; ++i) {
     long long cur=a[i].first*1LL*(pre[i+1]-(pre[n]-pre[i+1]))-prec[i+1]+(prec[n]-prec[i+1]);
     ans=min(ans,cur);
    }
    return ans;
}
};