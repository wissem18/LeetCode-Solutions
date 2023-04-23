class Solution {
public:
int jump(vector<int>&nums){
    int n=nums.size();
    if(n==1)
        return 0;
    int ans=1;
    int mx=nums[0];
    int i=1;
    while(mx<n-1){
        ans++;
        int j=mx;
        while(i<=j){
            mx=max(mx,nums[i]+i);
            i++;
        }
    }
    return ans;
}
};