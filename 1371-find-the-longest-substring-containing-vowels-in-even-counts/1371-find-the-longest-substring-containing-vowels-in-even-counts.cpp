class Solution {
public:
int findTheLongestSubstring(string s) {
    int n = s.size();
    int curbitmask = 0;
    string vowel = "aeiou";
    vector<int> prexor(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (find(vowel.begin(), vowel.end(), s[i]) != vowel.end()) {
            int x = find(vowel.begin(), vowel.end(), s[i]) - vowel.begin();
            prexor[i + 1] = prexor[i] ^ (1 << x);
        } else
            prexor[i + 1] = prexor[i];

    }
    unordered_map<int, int> leftocc;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        if (prexor[i] != 0) {
            if (leftocc.count(prexor[i])) {
                cur = i - leftocc[prexor[i]];
            } else
                leftocc[prexor[i]] = i;
        } else
            cur = i;

        ans = max(ans, cur);
    }
    return ans;
}

};