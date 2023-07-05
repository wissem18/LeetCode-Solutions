class Solution {
public:
int longestSubarray(vector<int>& nums) {
int ans=0;
int n =nums.size();
    int cur=0;
    int i=0;
    while(i<n){
        if(nums[i])
            cur++;
        else{
            int j=i+1;
            while(j<n&&nums[j]){
                cur++;
                j++;
            }
         ans=max(ans,cur);
         cur=0;   
        }
        
        i++;
    }
    ans=max(ans,cur-1);
    return ans;
}
};