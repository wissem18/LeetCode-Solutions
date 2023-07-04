class Solution {
public:
       int singleNumber(vector<int>& nums) {
        vector<int>occ(32,0);
        for (int i = 0; i < nums.size(); ++i) {
            int x=nums[i];
            for (int j = 0; j < 32; ++j) {
                if(x&(1<<j))
                    occ[j]++;
            }
        }
        int ans=0;
        for (int i = 0; i < 32; ++i) {
            if(occ[i]%3==1){
                ans+=(1<<i);
            }
        }
        return ans;
    }
};