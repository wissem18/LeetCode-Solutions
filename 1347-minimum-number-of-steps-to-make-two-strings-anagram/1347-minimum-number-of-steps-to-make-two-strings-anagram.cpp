class Solution {
public:
int minSteps(string s, string t) {
vector<int>a(26,0),b(26,0);
    for (int i = 0; i < s.size(); ++i) {
        a[s[i]-'a']++;
        b[t[i]-'a']++;
    }
    int ans=0;
    for (int i = 0; i < 26; ++i) {
        ans+=abs(a[i]-b[i]);
    }
    return ans/2;
}
};