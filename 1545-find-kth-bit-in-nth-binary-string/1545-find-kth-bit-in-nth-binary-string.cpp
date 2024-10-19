class Solution {
public:
char findKthBit(int n, int k) {
    string s = "0";
    while (k > s.size()) {
        string cur = s;
        s += "1";
        for (int i = 0; i < cur.size(); ++i) {
            if (cur[i] == '0')
                cur[i] = '1';
            else
                cur[i] = '0';
        }
        for (int i = cur.size() - 1; i >= 0; --i) {
            s += cur[i];
        }
    }
    return s[k-1];
}
};