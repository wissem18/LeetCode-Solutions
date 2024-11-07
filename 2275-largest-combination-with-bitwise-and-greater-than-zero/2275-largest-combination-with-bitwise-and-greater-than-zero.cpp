class Solution {
public:
int largestCombination(vector<int> &candidates) {
    int n = candidates.size();
    vector<int> cnt(24, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 24; ++j) {
            if ((1 << j) & candidates[i])
                cnt[j]++;
        }
    }
    int ans = *max_element(cnt.begin(), cnt.end());
    return ans;
}
};