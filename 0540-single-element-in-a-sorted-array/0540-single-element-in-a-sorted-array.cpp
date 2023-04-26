class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
    while(l<r){
        int mid=(l+r)/2;
        bool t1= false;
        bool t2= false;
        if(mid+1<n)
           t2=(nums[mid]==nums[mid+1]);
        if(l-1>=0)
            t1=(nums[l]==nums[l-1]);
        if((mid-l+1)%2){
                if(t1==t2)
                    r=mid;
                else
                    l=mid+1;
        }
        else{
                if(t1!=t2)
                    r=mid;
                else
                    l=mid+1;
        }
    }
    return nums[l];
    }
};