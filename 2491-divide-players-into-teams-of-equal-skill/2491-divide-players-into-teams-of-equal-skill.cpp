class Solution {
public:
long long dividePlayers(vector<int> &skill) {
    int sum = 0;
    int n = skill.size();
    for (int i = 0; i < n; ++i) {
        sum += skill[i];
    }
    if (sum % (n / 2))
        return -1;
    sort(skill.begin(), skill.end());
    int target = (2 * sum) / n;
    long long ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (skill[i] + skill[n - 1 - i] != target)
            return -1;
        ans += skill[i] * skill[n - i - 1];
    }
    return ans;
}
};