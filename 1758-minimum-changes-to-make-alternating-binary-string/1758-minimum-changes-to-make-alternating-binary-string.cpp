class Solution {
public:
int minOperations(string s) {
    int n = s.size();
    int cnt = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] - '0' != cur)
            cnt++;
        cur ^= 1;
    }
    return min(cnt, n-cnt);
}
};