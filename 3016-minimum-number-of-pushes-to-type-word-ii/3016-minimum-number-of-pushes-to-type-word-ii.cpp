class Solution {
public:
int minimumPushes(string word) {
    unordered_map<char, int> occ;
    set<char> s;
    for (char c: word) {
        occ[c]++;
        s.insert(c);
    }
    vector<char> chars(s.begin(), s.end());
    sort(chars.begin(), chars.end(), [&occ](char &a, char &b) { return occ[a] > occ[b]; });
    int ans = 0;
    for (int i = 0; i < chars.size(); ++i) {
        ans += occ[chars[i]] * ceil((i + 1) / 8.0);
    }
    return ans;
}
};