class Solution {
public:
int minOperations(vector<int>& nums) {
    int g=0;
    int cnt=0;
    for (int i = 0; i < nums.size(); ++i) {
      g=gcd(g,nums[i]);
      if(nums[i]==1)
          cnt++;
    }
    if(cnt!=0)
       return nums.size()-cnt;
    else if(g!=1)
        return -1;
    else{
        int ans=1e9;

        for (int i = 0; i < nums.size(); ++i) {
            int cumg=0;
            for (int j = i; j <nums.size() ; ++j) {
                cumg=gcd(cumg,nums[j]);
                if(cumg==1){
                    ans=min(ans,j-i+(int)nums.size()-1);
                }
            }
        }
        return ans;
    }
}


};