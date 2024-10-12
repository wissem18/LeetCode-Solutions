class Solution {
public:
int minGroups(vector<vector<int>> &intervals) {
    int mx = 0;
    for (int i = 0; i < intervals.size(); ++i) {
        mx = max(mx, intervals[i][1]);
    }
    vector<int> points(mx + 2, 0);
    for (auto interval: intervals) {
        points[interval[0]]++;
        points[interval[1] + 1]--;
    }
    for (int i = 1; i <= mx; ++i) {
        points[i] += points[i - 1];
    }
    int ans = *max_element(points.begin(), points.end());
    return ans;
}
};