class Solution {
public:
vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    vector<pair<int, int>> queries_with_index;
    int q = queries.size();
    for (int i = 0; i < q; ++i) {
        queries_with_index.push_back({queries[i], i});
    }
    sort(queries_with_index.begin(), queries_with_index.end());
    vector<int> ans(q);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 0; i < items.size(); ++i) {
        pq.push({items[i][0], items[i][1]});
    }
    int mx = 0;
    for (int i = 0; i < q; ++i) {
        int cur = queries_with_index[i].first;
        int index = queries_with_index[i].second;
        while (!pq.empty() && pq.top().first <= cur)
            mx = max(mx, pq.top().second), pq.pop();
        ans[index] = mx;
    }
    return ans;
}
};