class Solution {
public:
int maxFrequency(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<long long>pre(n+1,0);
    for (int i = 0; i < n; ++i) {
        pre[i+1]=pre[i]+nums[i];
    }
    int ans=1;
    for (int i =n-1; i >=0; --i) {
      int l=0,r=i;
        if(i-l+1<=ans)
            break;
      while(l<r){
          int mid=(l+r)/2;
          long long cur=pre[i]-pre[mid];
          if(nums[i]*1LL*(i-mid)-cur>k){
              l=mid+1;
          }
          else
              r=mid;
      }
      ans=max(ans,i-l+1);
    }
    return ans;
}
};