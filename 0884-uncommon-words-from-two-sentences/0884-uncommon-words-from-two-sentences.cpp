class Solution {
public:
vector<string> uncommonFromSentences(string s1, string s2) {
    map<string, int> mp1, mp2;
    unordered_set<string> st2, st1;
    string cur = "";
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == ' ') {
            mp1[cur]++;
            st1.insert(cur);
            cur = "";
        } else
            cur += s1[i];
    }
    mp1[cur]++;
    st1.insert(cur);
    cur = "";
    for (int i = 0; i < s2.size(); ++i) {
        if (s2[i] == ' ') {
            mp2[cur]++;
            st2.insert(cur);
            cur = "";
        } else
            cur += s2[i];
    }
    mp2[cur]++;
    st2.insert(cur);
    vector<string> ans;
    for (auto &[s, cnt]: mp1) {
        if (cnt > 1)continue;
        if (!st2.count(s))
            ans.push_back(s);
    }
    for (auto &[s, cnt]: mp2) {
        if (cnt > 1)continue;
        if (!st1.count(s))
            ans.push_back(s);
    }
    return ans;
}
};