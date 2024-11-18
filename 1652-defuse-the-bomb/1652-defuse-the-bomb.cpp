class Solution {
public:
vector<int> decrypt(vector<int> &code, int k) {
    int n = code.size();
    vector<int> ans(n);
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = code[i] + pre[i];
    }
    for (int i = 0; i < n; ++i) {
        if (k == 0) {
            ans[i] = 0;
        }
        if (k < 0) {
            int ind = (i + k + n) % n;
            ans[i] = 0;
            if (ind > i) {
                ans[i] += pre[n] - pre[ind];
                ans[i] += pre[i];
            } else {
                ans[i] += pre[i] - pre[ind];
            }
        }
        if (k > 0) {
            int ind = (i + k) % n;
            ans[i] = 0;
            if (ind < i) {
                ans[i] += pre[n] - pre[i + 1];
                ans[i] += pre[ind + 1];
            } else {
                ans[i] += pre[ind + 1] - pre[i + 1];
            }
        }
    }
    return ans;
}
};