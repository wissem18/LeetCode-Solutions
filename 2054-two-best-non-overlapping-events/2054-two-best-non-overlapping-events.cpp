class Solution {
public:
int maxTwoEvents(vector<vector<int>> &events) {
    sort(events.begin(), events.end());
    int n = events.size();
    vector<int> mxright(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        mxright[i] = max(mxright[i + 1], events[i][2]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = events[i][2];
        vector<int> a = {events[i][1] + 1, 0, 0};
        int nextpos = lower_bound(events.begin(), events.end(), a) - events.begin();
        cur += mxright[nextpos];
        ans = max(ans, cur);
    }
    return ans;
}
};