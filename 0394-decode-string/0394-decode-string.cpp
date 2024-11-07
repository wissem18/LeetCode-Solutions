class Solution {
public:
string rec(int &i, string &s) {
    int k = 0;
    string cur;
    for (; i < s.size(); ++i) {
        if (s[i] == '[') {
            string curstr = rec(++i, s);
            for (; k > 0; k--) cur += curstr;
        } else if (s[i] == ']')
            return cur;
        else if (s[i] >= '0' && s[i] <= '9')
            k = k * 10 + s[i] - '0';
        else
            cur += s[i];
    }
    return cur;
}

string decodeString(string s) {
    int i = 0;
    return rec(i, s);
}

};