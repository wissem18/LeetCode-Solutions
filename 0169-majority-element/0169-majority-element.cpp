class Solution {
public:
int majorityElement(vector<int> &nums) {
int n=nums.size();
int votes=0,ans=-1;
    for (int i = 0; i < n; ++i) {
        if(!votes){
            ans=nums[i];
            votes=1;
        }
        else if(nums[i]==ans)votes++;
        else votes--;
    }
    return ans;
}
};