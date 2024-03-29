class Solution {
public:
long long countSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    int mx = *max_element(nums.begin(), nums.end());
    int i = 0,j=0;
    int cnt=0;
    long long ans=0;
    while (i < n){
       while(j<n&&cnt<k){
           if(nums[j]==mx)
               cnt++;
           j++;
       }
       if(cnt==k){
           ans+=n-j+1;
       }
       if(nums[i]==mx)
           cnt--;
       i++;
    }
    return ans;
}
};