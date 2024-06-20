class Solution {
public:

int maxDistance(vector<int> &position, int m) {
    int n = position.size();
    sort(position.begin(), position.end());
    int l = 1, r = 1e9;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        int cur = 0;
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (position[i] - position[cur] >= mid) {
                cur = i;
                cnt++;
            }
        }
        if (cnt >= m)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
};