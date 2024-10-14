class Solution {
public:
long long maxKelements(vector<int> &nums, int k) {
    int n = nums.size();
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
        pq.push(nums[i]);
    }
    long long ans = 0;
    while (k--) {
        int t = pq.top();
        pq.pop();
        ans += t;
        pq.push(ceil(t / 3.0));
    }
    return ans;
}
};