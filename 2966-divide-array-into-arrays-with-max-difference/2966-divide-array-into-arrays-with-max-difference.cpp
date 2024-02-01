class Solution {
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    bool test = true;
    for (int i = 0; i <n; i+=3) {
         if(nums[i+2]-nums[i]>k){
             test= false;
             break;
         }   
    }
    if(test){
        vector<vector<int>>ans(n/3);
        int j=0;
        for (int i = 0; i < n; i+=3) {
            for (int l = 0; l < 3; ++l) {
                ans[j].push_back(nums[i+l]);
            }
            j++;
        }
        return ans;
    }
    else
        return {};
}
};