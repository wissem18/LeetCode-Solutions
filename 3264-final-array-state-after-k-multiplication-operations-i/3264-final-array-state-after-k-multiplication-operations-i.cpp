class Solution {
public:
vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 0; i < nums.size(); ++i) {
        pq.push({nums[i], i});
    }
    while (k--) {
        auto t = pq.top();
        pq.pop();
        pq.push({t.first * multiplier, t.second});
    }
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        nums[t.second] = t.first;
    }
    return nums;
}
};