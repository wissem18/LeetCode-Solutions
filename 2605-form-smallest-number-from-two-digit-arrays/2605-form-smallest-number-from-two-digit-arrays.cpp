class Solution {
public:
   int minNumber(vector<int>& nums1, vector<int>& nums2) {
sort(nums1.begin(),nums1.end());
sort(nums2.begin(),nums2.end());
    for (int i = 0; i < nums1.size(); ++i) {
        if(lower_bound(nums2.begin(),nums2.end(),nums1[i])!=upper_bound(nums2.begin(),nums2.end(),nums1[i]))
            return nums1[i];
    }
    int mn=min(nums1[0],nums2[0]);
    int mx=max(nums1[0],nums2[0]);
    return mn*10+mx;
}
};