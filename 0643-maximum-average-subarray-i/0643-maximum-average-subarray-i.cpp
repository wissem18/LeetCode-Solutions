class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int curwindow=0;
        for(int i=0;i<k;i++){
            curwindow+=nums[i];
        }
        int ans=curwindow;
        for(int i=k;i<nums.size();i++){
            curwindow+=nums[i];
            curwindow-=nums[i-k];
            ans=max(curwindow,ans);
        }
        return (ans*1.0)/k;
    }
};