class Solution {
public:
  
int minimizeArrayValue(vector<int>& nums) {
    int n=nums.size();
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r)/2;
        bool test=true;
        long long sum=0;
        for (int i = 0; i < n; ++i) {
            sum+=nums[i];
            if(mid*1LL*(i+1)<sum){
                test=false;
                break;
            }
        }
        if(test)
            r=mid;
        else
            l=mid+1;
    }
    return l;
}
};