class Solution {
public:

bool search(vector<int>& nums, int target) {

    int n=nums.size();
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]==target)
            return true;
        if(nums[l]==nums[mid]){// we can't do bs because target might be in the First or Second array
            l++;
            continue;
        }
        bool midpos=nums[l]<=nums[mid];
        bool targetpos=nums[l]<=target;
        if(midpos!=targetpos){
            if(midpos)//the mid is in F and target in S
                l=mid+1;
            else//the mid in S and target in F 
                r=mid-1;
        }
        else{//mid and target lies in the same array 
            if(nums[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
    }
    return false;
}
};