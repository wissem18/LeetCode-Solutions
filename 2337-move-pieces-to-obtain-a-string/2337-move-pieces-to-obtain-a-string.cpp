class Solution {
public:
bool canChange(string start, string target) {
    string order = "";
    for (auto c: start) {
        if (c != '_')
            order += c;
    }
    int j = 0;
    for (auto c: target) {
        if (c != '_') {
            if (j < order.size() && c == order[j])
                j++;
            else
                return false;
        }
    }
    if (j != order.size())
        return false;
    int r = 0;
    for (int i = 0; i < start.size(); ++i) {
        if (start[i] == 'R')
            r++;
        if (start[i] == 'L')
            r = 0;
        if (target[i] == 'R') {
            if (r == 0)
                return false;
            else
                r--;
        }
    }

    int l = 0;
    for (int i = start.size() - 1; i >= 0; --i) {
        if (start[i] == 'L')
            l++;
        if (start[i] == 'R')
            l = 0;
        if (target[i] == 'L') {
            if (l == 0)
                return false;
            else
                l--;
        }
    }
    return true;
}
};