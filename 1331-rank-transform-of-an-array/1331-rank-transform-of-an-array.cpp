class Solution {
public:
vector<int> arrayRankTransform(vector<int> &arr) {
    vector<pair<int, int>> a;
    for (int i = 0; i < arr.size(); ++i) {
        a.push_back(make_pair(arr[i], i));
    }
    sort(a.begin(), a.end());
    vector<int> ans(arr.size());
    int rank = 1;
    for (int i = 0; i < a.size(); ++i) {
        ans[a[i].second] = rank;
        if (i + 1 < a.size() && a[i + 1].first != a[i].first)
            rank++;
    }
    return ans;
}
};