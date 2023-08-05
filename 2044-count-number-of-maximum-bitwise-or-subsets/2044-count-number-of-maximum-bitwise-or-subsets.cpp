class Solution {
public:
int countMaxOrSubsets(vector<int>& nums) {
int n=nums.size();
int ans=0;
int cnt=0;
    for (int i = 1; i <(1<<n) ; ++i) {
        int cur=0;
        for (int j = 0; j < n; ++j) {
            if(i&(1<<j))
                cur|=nums[j];
        }
        if(cur>ans){
        ans=cur;
        cnt=1;
        }
        else if(cur==ans)
            cnt++;
    }
    return cnt;
}
};