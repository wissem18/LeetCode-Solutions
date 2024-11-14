class Solution {
public:
int minimizedMaximum(int n, vector<int> &quantities) {
    int l = 1, r = 1e5;
    while (l < r) {
        int mid = (l + r) / 2;
        long long cnt = 0;
        for (int i = 0; i < quantities.size(); ++i) {
            cnt += (quantities[i] + mid - 1) / mid;
        }
        if (cnt > n)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
};