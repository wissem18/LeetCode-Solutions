class Solution {
public:
 int maxDivScore(vector<int>& nums, vector<int>& divisors) {
    int ans=1e9;
    int mx=0;
    for (int i = 0; i < divisors.size(); ++i) {
        int cur=0;
        for (int j = 0; j < nums.size(); ++j) {
            if(nums[j]% divisors[i]==0)
                cur++;
        }
        if(cur>mx){
            mx=cur;
            ans= divisors[i];
        }
        else if(mx==cur){
            ans=min(ans,divisors[i]);
        }
    }
    return ans;
}
};