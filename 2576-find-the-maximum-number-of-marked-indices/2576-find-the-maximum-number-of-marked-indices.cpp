class Solution {
public:
int maxNumOfMarkedIndices(vector<int>& nums) {
sort(nums.begin(),nums.end());
vector<bool>vis(nums.size(),false);
int ans=0;
int last=nums.size()/2;
    for (int i = 0; i < nums.size(); ++i) {
        if(vis[i])
            continue;
        int x= lower_bound(nums.begin(),nums.end(),2*nums[i])-nums.begin();
        if(x==nums.size())
            break;
        int j=max(x,last);
        if(!vis[j]){
            ans+=2;
            vis[j]=true;
            last=j;
        }
        else{
            if(j+1<nums.size()&&!vis[j+1]){
                ans+=2;
                vis[j+1]=true;
                last=j+1;   
            }
        }
    }
    return ans;
}
};