class Solution {
public:
int n;
vector<pair<pair<int, int>, int>> x;
vector<int> mem;

int dp(int i) {
    if (i >= n)
        return 0;
    if (mem[i] != -1)
        return mem[i];
    int ans = dp(i + 1);
    pair<pair<int, int>, int> s = {{x[i].first.second, 0}, 0};
    int j = lower_bound(x.begin(), x.end(), s) - x.begin();
    ans = max(ans, dp(j) + x[i].second);
    return mem[i] = ans;
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
    n = startTime.size();
    x.resize(n);
    for (int i = 0; i < n; ++i) {
        x[i] = {{startTime[i], endTime[i]}, profit[i]};
    }
    sort(x.begin(), x.end());
    mem.assign(n + 1, -1);
    return dp(0);
}
};