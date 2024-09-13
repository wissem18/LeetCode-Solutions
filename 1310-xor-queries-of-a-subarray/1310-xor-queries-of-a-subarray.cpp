class Solution {
public:
vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    int n = arr.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] ^ arr[i];
    }
    vector<int> ans;
    for (auto query: queries) {
        int l = query[0], r = query[1];
        ans.push_back(pre[r + 1] ^ pre[l]);
    }
    return ans;
}
};