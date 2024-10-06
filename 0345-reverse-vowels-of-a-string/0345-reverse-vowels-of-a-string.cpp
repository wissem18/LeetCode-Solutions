class Solution {
public:
string reverseVowels(string s) {
    string vowels = "aeuoi";
    string v = "";
    for (int i = 0; i < s.size(); ++i) {
        if (vowels.find(tolower(s[i])) != string::npos) {
            v = s[i] + v;
        }
    }
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (vowels.find(tolower(s[i])) != string::npos) {
            s[i] = v[j++];
        }
    }
    return s;
}
};