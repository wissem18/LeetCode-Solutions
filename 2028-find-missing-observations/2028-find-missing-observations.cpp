class Solution {
public:
vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
    int sum = 0;
    int m = rolls.size();

    for (int i = 0; i < m; ++i) {
        sum += rolls[i];
    }
    int rem = (n + m) * mean - sum;
    if (rem < n || rem > 6 * n)
        return {};
    vector<int> ans(n, rem / n);
    for (int i = 0; i < rem % n; ++i) {
        ans[i]++;
    }
    return ans;
}
};