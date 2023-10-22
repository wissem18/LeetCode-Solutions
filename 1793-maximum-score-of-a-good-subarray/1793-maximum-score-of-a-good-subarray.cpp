class Solution {
public:
int maximumScore(vector<int> &nums, int k) {
    int n = nums.size();
    int mn = nums[k];
    int i = k - 1, j = k + 1;
    int ans = mn;
    int len=1;
    while (i >= 0 && j < n){
            if(nums[i]>=nums[j]){
              int cur=min(mn,nums[i])*(len+1);
              ans=max(ans,cur);
              mn=min(mn,nums[i]);
              len++;
              i--;
            }
            else{
                int cur=min(mn,nums[j])*(len+1);
                ans=max(ans,cur);
                mn=min(mn,nums[j]);
                len++;
                j++;
            }
    }
    if(i<0){
        while(j<n){
            int cur=min(mn,nums[j])*(len+1);

            ans=max(ans,cur);
            mn=min(mn,nums[j]);
            len++;
            j++;
        }
    }
    else if(j==n){
        while(i>=0){
            int cur=min(mn,nums[i])*(len+1);
            ans=max(ans,cur);
            mn=min(mn,nums[i]);
            len++;
            i--;
        }
    }
    return ans;
}
};