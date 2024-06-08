class Solution {
public:
bool checkSubarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> occ;
    int n = nums.size();
    int sum = 0;
    int lst=-1;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        int x = sum % k;
        if (x == 0 && i > 0) {
            return true;
        }
        if (occ[x]>1||(occ[x]==1&&lst!=x))
            return true;
        occ[x]++;
        lst=x;  
    }
    return false;
}
};