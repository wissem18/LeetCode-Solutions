class Solution {
public:
vector<int> prefix_function(string s) {
    int n = (int) s.length();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

string shortestPalindrome(string s) {
    string rev=string(s.rbegin(),s.rend());
    string temp = s + "#"+rev;
    vector<int> pref = prefix_function(temp);
    int longest_pref_pal = pref[temp.size() - 1];
    string add=rev.substr(0,s.size()-longest_pref_pal);
    return add+s;
}
};