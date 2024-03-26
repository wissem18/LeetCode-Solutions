class Solution {
public:
int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    bool mex_is_one=true;
    for (int i = 0; i < n; ++i) {
        if(nums[i]==1)
            mex_is_one=false;
        if(nums[i]<=0||nums[i]>n){
            nums[i]=1;
        }
    }
    if(mex_is_one)
        return 1;
    for (int i = 0; i < n; ++i) {
        nums[nums[i]%(n)] +=n;
    }
    for (int i = 2; i < n; ++i) {
        if((nums[i]/n)<(1+(nums[i]%n==0)))
            return i;
    }
     if((nums[0]/n)<(1+(nums[0]%n==0)))
         return n;
     return n+1;
}
};