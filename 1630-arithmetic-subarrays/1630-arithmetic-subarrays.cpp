class Solution {
public:
vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
    int n = nums.size();
    int m = l.size();
    vector<bool> ans;
    for (int i = 0; i < m; ++i) {
        int left = l[i], right = r[i];
        if (left >= right)continue;
        vector<int> a;
        for (int j = left; j <= right; ++j) {
            a.push_back(nums[j]);
        }
        sort(a.begin(), a.end());
        bool test = true;
        int dif = a[1] - a[0];
        for (int j = 2; j < a.size(); ++j) {
            if (a[j] - a[j - 1] != dif) {
                test=false;
                break;
            }
        }
        ans.push_back(test);
    }
    return ans;
}
};