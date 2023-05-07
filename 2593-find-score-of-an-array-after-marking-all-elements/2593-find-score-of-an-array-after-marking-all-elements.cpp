class Solution {
public:
long long findScore(vector<int>& nums) {
    priority_queue<pair<int,int>>q;
    vector<bool>vis(nums.size(),false);
    for (int i = 0; i < nums.size(); ++i) {
        q.push({-nums[i],-i});
    }
    long long ans=0;
    while(!q.empty()){
        int x=-q.top().first;
        int ind=-q.top().second;
        q.pop();
        if(!vis[ind]){
            ans+=x;
            vis[ind]=true;
            if(ind!=nums.size()-1)
                vis[ind+1]=true;
            if(ind!=0)
                vis[ind-1]=true;
        }
    }
    return ans;
}
};