class Solution {
public:
int shortestSubarray(vector<int> &nums, int k) {
    int n = nums.size();
    int ans = INT_MAX;
    long long cum = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> prefixSumHeap;

    for (int i = 0; i < n; i++) {
        cum += nums[i];
        if (cum >= k) {
            ans = min(ans, i + 1);
        }

        while (!prefixSumHeap.empty() && cum - prefixSumHeap.top().first >= k) {
            ans = min(ans, i - prefixSumHeap.top().second);
            prefixSumHeap.pop();
        }
        prefixSumHeap.emplace(cum, i);
    }

    return ans == INT_MAX ? -1 : ans;
}
};