class Solution {
public:

int incremovableSubarrayCount(vector<int>& nums) {
int ans=0;
int n=nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j <n ; ++j) {
            vector<int>x;
            for (int k = 0; k < i; ++k) {
                x.push_back(nums[k]);
            }
            for (int k = j+1; k <n ; ++k) {
                x.push_back(nums[k]);
            }
            bool test= true;
            for (int k = 1; k <x.size() ; ++k) {
                if(x[k-1]>=x[k]){test=false;
                break;}
            }
            if(test)
                ans++;
        }
    }
    return ans;
}
};