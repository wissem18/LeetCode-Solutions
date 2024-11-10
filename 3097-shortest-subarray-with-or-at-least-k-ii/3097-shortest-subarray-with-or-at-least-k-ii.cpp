class Solution {
public:
int minimumSubarrayLength(vector<int> &nums, int k) {
    int n = nums.size();
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        int mx = 0;
        vector<int> occ(32, 0);
        for (int i = 0; i < mid; ++i) {
            for (int j = 0; j < 32; ++j) {
                if (nums[i] & (1 << j))
                    occ[j]++;
            }
        }
        for (int i = 0; i < 32; ++i) {
            if (occ[i])
                mx += (1 << i);
        }
        for (int i = mid; i < n; ++i) {
            for (int j = 0; j < 32; ++j) {
                if (nums[i - mid] & (1 << j))
                    occ[j]--;
            }
            for (int j = 0; j < 32; ++j) {
                if (nums[i] & (1 << j))
                    occ[j]++;
            }
            int cur = 0;
            for (int j = 0; j < 32; ++j) {
                if (occ[j])
                    cur += (1 << j);
            }
            mx = max(cur, mx);
        }
        if (mx < k)
            l = mid + 1;
        else
            r = mid;
    }
        if (l == n) {
        int mxor = 0;
        for (int i = 0; i < n; ++i) {
            mxor |= nums[i];
        }
        if (mxor < k)
            return -1;
    }
    return l;
}
};