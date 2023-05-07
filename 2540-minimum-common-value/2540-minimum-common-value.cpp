class Solution {
public:
   int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int ans=1e9+7;
    for (int i = 0; i < nums1.size(); ++i) {
        if(upper_bound(nums2.begin(),nums2.end(),nums1[i])-lower_bound(nums2.begin(),nums2.end(),nums1[i])!=0){
            ans=min(ans,nums1[i]);
        }
    }
    if(ans==1e9+7)
        return -1;
    else
        return ans;
}
};