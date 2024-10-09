class Solution {
public:
int minAddToMakeValid(string s) {
    int cnto = 0, cntc = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            cnto++;
        } else {
            if (cnto) {
                cnto--;
            } else
                cntc++;
        }
    }
    return cnto + cntc;
}
};