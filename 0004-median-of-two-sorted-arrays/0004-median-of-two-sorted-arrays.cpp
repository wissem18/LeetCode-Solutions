class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
if(nums1.size()>nums2.size())
    swap(nums1,nums2);
int n=nums1.size(),m=nums2.size();
int l=0,r=n;
while(l<=r){
    int midA=(l+r)/2;
    int resteB=(m+n+1)/2-midA;
    int mxlA=(midA==0)?INT_MIN:nums1[midA-1];
    int mnrA=(midA==n)?INT_MAX:nums1[midA];
    int mxlB=(resteB==0)?INT_MIN:nums2[resteB-1];
    int mnrB=(resteB==m)?INT_MAX:nums2[resteB];
    if(mxlA<=mnrB&&mxlB<=mnrA){
        if((m+n)%2)
            return max(mxlA,mxlB);
        else{
            return (max(mxlA,mxlB)+min(mnrA,mnrB))/2.0;
        }
    }
    if(mxlA>mnrB)
        r=midA-1;
    else
        l=midA+1;
}
return 0;
}
};