class Solution {
public:
set<string> st;
vector<string> ans;

void backtrack(int i, int lst, string cur, string &s) {
    if (i == s.size()) {
        if (lst == s.size()){
            cur.pop_back();
            ans.push_back(cur);
        }
        return;
    }
    cur += s[i];
    if (st.count(s.substr(lst, i - lst+1))) {
        cur += ' ';
        backtrack(i + 1, i + 1, cur, s);
        cur.pop_back();
    }
    backtrack(i + 1, lst, cur, s);
}

vector<string> wordBreak(string s, vector<string> &wordDict) {
    for (auto x: wordDict) {
        st.insert(x);
    }
    backtrack(0,0,"",s);
    return ans;
}
};