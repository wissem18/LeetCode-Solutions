class Solution {
public:
int minOperations(vector<int>& nums, int k) {
int n=nums.size();
int ans=0;
vector<bool>vis(n+1,false);
    for (int i = nums.size()-1; i >=0 ; --i) {
        vis[nums[i]]=true;
        ans++;
        bool test= true;
        for (int j = 1; j <=k ; ++j) {
            if(!vis[j]){
                test=false;
                break;
            }
        }
        if(test)
            break;
    }
    return ans;
}
};