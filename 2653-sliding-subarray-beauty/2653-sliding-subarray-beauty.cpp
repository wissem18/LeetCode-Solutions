class Solution {
public:
vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
vector<int>ans;
vector<int>occ(105,0);
    for (int i = 0; i < k; ++i) {
        occ[nums[i]+50]++;
    }
    int cnt=0;
    for (int i = 0; i <=50; ++i) {
        cnt+=occ[i];
        if(cnt>=x){
            ans.push_back(i-50);
            break;
        }
        if(i==50){
            ans.push_back(0);
        }
    }
    for (int i = k; i < nums.size(); ++i) {
        occ[nums[i]+50]++;
        occ[nums[i-k]+50]--;
        cnt=0;
        for (int j = 0; j <=50; ++j) {
            cnt+=occ[j];
            if(cnt>=x){
                ans.push_back(j-50);
                break;
            }
            if(j==50){
                ans.push_back(0);
            }
        }
    }
    return ans;
}
};