class Solution {
public:
    int longestSubarray(vector<int>& nums) {
int ans=0;
int n =nums.size();
vector<int>pre(n+1,0);
int l=0;
    for (int i = n-1; i >=0 ; --i) {
        if(nums[i]==1)
            l++;
        else
            l=0;
        pre[i]=l;
    }
    int cur=0;
    for (int i = 0; i < n; ++i) {
        if(nums[i])
            cur++;
        else{
            ans=max(ans,cur+pre[i+1]);
            cur=0;
        }
    }
    ans=max(ans,cur-1);
    return ans;
}
};