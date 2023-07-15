class Solution {
public:
vector<vector<int>>mem;
int dp(int i,int cnt,vector<vector<int>>&events){
if(i==events.size()||cnt==0)
    return 0;
if(mem[i][cnt]!=-1)
    return mem[i][cnt];
vector<int> temp = {events[i][1],INT_MAX,INT_MAX};
int next= upper_bound(events.begin(),events.end(),temp)-events.begin();
int ans=max(dp(i+1,cnt,events),dp(next,cnt-1,events)+events[i][2]);
return mem[i][cnt]=ans;
}
int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(),events.end());
    int n=events.size();
    mem.assign(n+1,vector<int>(k+1,-1));
    return dp(0,k,events);
}
};