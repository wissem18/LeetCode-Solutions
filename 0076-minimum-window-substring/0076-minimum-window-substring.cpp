class Solution {
public:
string minWindow(string s, string t) {
    map<char, int> occs, occt;
    for (int i = 0; i < t.size(); ++i) {
        occt[t[i]]++;
    }
    int i = 0, j = 0;
    string ans = "";
    int x = t.size();
    while (j < s.size()) {
        if (occt.count(s[j]) && occt[s[j]] > occs[s[j]]) {
            x--;
        }
        occs[s[j]]++;
        if (x == 0) {
            while (i < j && (!occt.count(s[i]) || occs[s[i]] > occt[s[i]])) {
                occs[s[i]]--;
                i++;
            }
            if (ans.empty() || ans.size() > j - i + 1)
                ans = s.substr(i, j - i + 1);
            occs[s[i]]--;
            x++;
            i++;

        }

        j++;
    }
    return ans;
}
};