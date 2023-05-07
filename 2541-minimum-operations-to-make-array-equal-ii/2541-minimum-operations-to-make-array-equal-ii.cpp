class Solution {
public:
long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
    int n=nums1.size();
    if(k==0){
        if(nums1==nums2)
            return 0;
        else
            return -1;
    }
    long long mx=0,mn=0;
    for (int i = 0; i < n; ++i) {
        if(nums1[i]>nums2[i]){
            long long x=nums1[i]-nums2[i];
            if(x%k)
                return -1;
            mx+=x;
        }
        if(nums1[i]<nums2[i]){
            long long x=nums2[i]-nums1[i];
            if(x%k)
                return -1;
            mn+=x;
        }
    }
    if(mx!=mn)
        return -1;
    return mx/k;
}
};