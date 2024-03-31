class Solution {
public:
int subarraysWithKDistinct(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> occ(n + 1, 0);
    int i = 0, j = 0;
    int ans = 0;
    int cur=0;
    while (i < n) {
        occ[nums[i]]++;
        if(occ[nums[i]]==1)
            k--;
        if(k<0){
            //don't forget that we will have k<0 from k==0 in which we have shrinked the            //window to the smallest one with distinct k and the left element is unique
            occ[nums[j]]--;//for sure it becomes 0 
            k++;
            j++;
            cur=0;
        }
        
           if(k==0){
           //increment the left pointer until we have the smallest window with k==0 and
           //ends at right pointer which will be the count of left element is 1 
           while(occ[nums[j]]>1){
               occ[nums[j]]--;
               j++;
               cur++;
           }
            ans+=(cur+1);
        }
        i++;
    }
return ans;
}
};