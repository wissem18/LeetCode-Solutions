class Solution {
public:
int maxSubarrayLength(vector<int>& nums, int k) {
int n=nums.size();
int i=0,j=0;
int ans=0;
map<int,int>occ;
while(j<n){
   if(occ[nums[j]]==k){
       occ[nums[i]]--;
       i++;
       ans=max(ans,j-i);
   } 
   else{
       occ[nums[j]]++;
       j++;
       ans=max(ans,j-i);
   }
}
return ans;
}
};