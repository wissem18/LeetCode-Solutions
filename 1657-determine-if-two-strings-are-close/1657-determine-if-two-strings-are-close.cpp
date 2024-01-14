class Solution {
public:
bool closeStrings(string word1, string word2) {
    if(word1.size()!=word2.size())
        return false;
vector<int>a(26,0),b(26,0);
    for (int i = 0; i < word1.size(); ++i) {
        a[word1[i]-'a']++;
        b[word2[i]-'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if((!a[i]&&b[i])||(a[i]&&!b[i]))
            return false;
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    return (a==b);
}
};