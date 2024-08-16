class Solution {
public:
int maxDistance(vector<vector<int>> &arrays) {
    set<pair<int, int>> s;
    for (int i = 0; i < arrays.size(); ++i) {
        s.insert({arrays[i][0], i});
        s.insert({arrays[i][arrays[i].size() - 1], i});

    }
    auto mn = *s.begin();
    auto mx = *prev(s.end());
    if (mn.second != mx.second)
        return mx.first - mn.first;
    if (s.size() > 2) {
        auto smn = *next(s.begin());
        auto smx = *prev(prev(s.end()));
        return max(mx.first - smn.first, smx.first - mn.first);
    }
    return 0;
}
};