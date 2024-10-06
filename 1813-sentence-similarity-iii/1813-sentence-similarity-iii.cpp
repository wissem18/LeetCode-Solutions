class Solution {
public:
bool areSentencesSimilar(string sentence1, string sentence2) {
    int n = sentence1.size();
    int m = sentence2.size();
    if(sentence1==sentence2)
        return true;
    //in the beginning of the sentence
    string s11 = sentence1;
    string s22 = sentence2;
    if (s11.size() > s22.size()) {
        string tmp = s11;
        s11 = s22;
        s22 = tmp;
    }
    if (s22.substr(s22.size() - s11.size()) == s11 &&
        (s11.size() != s22.size() && s22[s22.size() - s11.size() - 1] == ' '))
        return true;
    //in the middle of the sentence
    int i = 0;
    for (; i < min(n, m); ++i) {
        if (sentence1[i] == ' ' && sentence2[i] == ' ' && (sentence1.substr(0, i) == sentence2.substr(0, i))) {
            string s1 = sentence1.substr(i + 1);
            string s2 = sentence2.substr(i + 1);

            if (s1.size() > s2.size()) {
                string tmp = s1;
                s1 = s2;
                s2 = tmp;
            }
            int sz = s2.size() - s1.size();
            if (s2.substr(sz) == s1 && (sz > 0 && s2[sz - 1] == ' '))
                return true;

        }
    }
    //in the end of the sentence
    if (sentence1.substr(0, i) == sentence2.substr(0, i)) {
        if ((i == n && sentence2[i] == ' ') || (i == m && sentence1[i] == ' '))
            return true;
    }
    return false;
}
};