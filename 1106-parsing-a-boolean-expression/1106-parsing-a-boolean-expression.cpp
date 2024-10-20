class Solution {
public:
bool rec(int &i, string &s) {
    char cur = s[i];
    i++;
    if (cur == 'f')return false;
    if (cur == 't')return true;
    if (cur == '!') {
        i++;//skip (
        bool ans = !rec(i, s);
        i++; // skip )
        return ans;
    }
    if (cur == '&') {
        i++;
        vector<bool> ans;
        while (s[i] != ')') {
            if (s[i] != ',') {
                ans.push_back(rec(i, s));
            } else
                i++;
        }
        i++;
        for (auto x: ans) {
            if (!x)
                return false;
        }
        return true;
    }
    if (cur == '|') {
        i++;
        vector<bool> ans;
        while (s[i] != ')') {
            if (s[i] != ',') {
                ans.push_back(rec(i, s));
            } else
                i++;
        }
        i++;
        for (auto x: ans) {
            if (x)
                return true;
        }
        return false;
    }
    return false;
}

bool parseBoolExpr(string expression) {
    int i=0;
    return rec(i, expression);
}
};