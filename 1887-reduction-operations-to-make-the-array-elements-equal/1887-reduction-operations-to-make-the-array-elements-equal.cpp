class Solution {
public:
int reductionOperations(vector<int>& nums) {
int n=nums.size();
vector<int>occ(50001,0);
int mn=1e9;
    for (int i = 0; i <n ; ++i) {
        occ[nums[i]]++;
        mn=min(mn,nums[i]);
    }
    int cur=0;
    int ans=0;
    for (int i = 50000; i >0 ; --i) {
        if(i==mn)
            break;
        if(!occ[i])continue;
        cur+=occ[i];
        ans+=cur;
    }
    return ans;
}
};