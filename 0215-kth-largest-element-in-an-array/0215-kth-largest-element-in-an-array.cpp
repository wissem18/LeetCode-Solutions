class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
vector<int>occ(2e4+2,0);
    for (int i = 0; i < nums.size(); ++i) {
        occ[nums[i]+1e4]++;
    }
    int ans=0;
    for (int i = 2e4; i >=0; --i) {
        k-=occ[i];
        if(k<=0)
        {
            ans=i-1e4;
            break;
        } 
    }
    return ans;
}
};