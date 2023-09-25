class Solution {
public:
    char findTheDifference(string s, string t) {
vector<int>cntS(26,0),cntT(26,0);
    for (int i = 0; i < s.size(); ++i) {
        cntS[s[i]-'a']++;
    }
    for (int i = 0; i < t.size(); ++i) {
        cntT[t[i]-'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if(cntS[i]!=cntT[i])
            return char('a'+i);
    }
 return 'a';   
}
};