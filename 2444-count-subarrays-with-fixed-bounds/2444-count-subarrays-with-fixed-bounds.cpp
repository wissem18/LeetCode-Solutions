class Solution {
public:
long long countSubarrays(vector<int> &nums, int minK, int maxK) {
    int mnp=-1,mxp=-1,p=-1;
    long long ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
       if(nums[i]>maxK||nums[i]<minK)
           p=i;
       if(nums[i]==minK)
           mnp=i;
       if(nums[i]==maxK)
           mxp=i;
       ans+=max(0,min(mxp,mnp)-p);
    }
    return ans;
}
    
};