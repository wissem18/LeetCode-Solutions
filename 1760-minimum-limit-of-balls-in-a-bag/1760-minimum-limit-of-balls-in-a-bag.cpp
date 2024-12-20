class Solution {
public:
int minimumSize(vector<int> &nums, int maxOperations) {
    int l = 1, r = 1e9;
    while (l < r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cnt += (nums[i] - 1) / mid;
        }
        if (cnt > maxOperations)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
};