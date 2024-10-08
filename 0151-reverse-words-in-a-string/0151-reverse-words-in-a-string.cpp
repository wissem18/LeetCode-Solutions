class Solution {
public:
string reverseWords(string s) {
    vector<string> a;
    string cur = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            if (!cur.empty()) {
                a.push_back(cur);
                cur = "";
            }
            continue;
        }
        cur += s[i];
    }
    if (!cur.empty())
        a.push_back(cur);
    string ans = "";
    for (int i = a.size() - 1; i >= 0; --i) {
        ans += a[i];
        ans += " ";
    }
    ans.pop_back();
    return ans;
}
};