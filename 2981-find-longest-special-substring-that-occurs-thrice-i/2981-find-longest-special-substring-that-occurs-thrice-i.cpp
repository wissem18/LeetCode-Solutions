class Solution {
public:
int maximumLength(string s) {
    int n = s.size();
    map<string, int> occ;
    for (int i = 0; i < n; ++i) {
        string cur = "";
        cur += s[i];
        occ[cur]++;
        for (int j = i + 1; j < n; ++j) {
            if (s[j] != s[i])
                break;
            else {
                cur += s[j];
                occ[cur]++;
            }
        }
    }
    int ans = -1;
    for (auto [t, cnt]: occ) {
        if (cnt >= 3)
            ans = max(ans, int(t.size()));
    }
    return ans;
}
};