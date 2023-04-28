class Solution {
public:
  int subarraysDivByK(vector<int>& nums, int k) {
        int occ[k];
        int n=nums.size();
      memset(occ,0,sizeof occ);
        int sum=0;
        int ans=0;
      for (int i = 0; i < n; ++i) {
          sum+=nums[i];
          int x=(sum%k+k)%k;
          if(x==0){
              ans++;
          }
          if(x<0)
              x=k+x;
          ans+=occ[x];
          occ[x]++;
      }
     return ans;

    }
};