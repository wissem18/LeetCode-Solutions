class Solution {
public:
long long minEnd(int n, int x) {
    priority_queue<int> pq;
    for (int i = 0; i < 64; ++i) {
        if (!(x & (1LL << i)))
            pq.push(i);
    }
    int cnt = pq.size() - 1;
    long long ans = x;
    n -= 1;
    while (n) {
        int cur = pq.top();
        pq.pop();
        if ((1LL << cnt) <= n) {
            n -= (1LL << cnt);
            ans += (1LL << cur);
        }
        cnt--;
    }
    return ans;
}
};