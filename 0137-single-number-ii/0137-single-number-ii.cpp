class Solution {
public:
      int singleNumber(vector<int>& nums) {
        int ans=0;
        for (int i = 0; i < 32; ++i) {
            int cnt=0;
            for (int j = 0; j < nums.size(); ++j) {
                cnt+=(nums[j]&(1<<i))?1:0;
            }
            if(cnt%3==1)
                ans+=(1<<i);
        }
        return ans;
    }
};