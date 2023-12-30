class Solution {
public:
bool makeEqual(vector<string> &words) {
    vector<int> cnt(26, 0);
    int n = words.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            cnt[words[i][j] - 'a']++;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] %n)
            return false;
    }
    return true;
}
};