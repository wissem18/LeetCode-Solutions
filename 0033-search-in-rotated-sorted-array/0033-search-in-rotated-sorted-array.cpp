class Solution {
public:
int findpivot(vector<int>& nums){
    int l=0, r=nums.size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[nums.size()-1]<nums[mid]){
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return l;
}
int search(vector<int>& nums, int target) {
int x= findpivot(nums);
int n=nums.size();
int l=x,r=n+x-1;
while(l<=r){
    int mid=(l+r)/2;
    if(nums[mid%n]==target)
        return mid%n;
    if(nums[mid%n]<target)
        l=mid+1;
    else
        r=mid-1;
}
return -1;
}
};