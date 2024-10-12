class Solution {
public:
int minGroups(vector<vector<int>> &intervals) {
    vector<int> points(1e6 + 2, 0);
    for (auto interval: intervals) {
        points[interval[0]]++;
        points[interval[1] + 1]--;
    }
    for (int i = 1; i <= 1e6; ++i) {
        points[i] += points[i - 1];
    }
    int ans = *max_element(points.begin(), points.end());
    return ans;
}
};