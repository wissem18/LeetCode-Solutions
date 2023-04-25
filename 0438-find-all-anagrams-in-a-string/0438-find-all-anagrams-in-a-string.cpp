class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    vector<int>res;
if(s.size()<p.size())
    return res;
vector<int>occ(26,0);
    for (int i = 0; i < p.size(); ++i) {
        occ[p[i]-'a']++;
    }
    vector<int>occ2(26,0);
    for (int i = 0; i < p.size(); ++i) {
        occ2[s[i]-'a']++;
    }
    bool test= true;
    for (int i = 0; i < 26; ++i) {
        if(occ[i]!=occ2[i]){
            test= false;
            break;}
    }
    if(test)
        res.push_back(0);
    for (int i = p.size(); i < s.size(); ++i) {
       occ2[s[i]-'a']++;
        occ2[s[i-p.size()]-'a']--;
        bool t= true;
        for (int j = 0; j < 26; ++j) {
            if(occ[j]!=occ2[j]){
                t= false;
                break;}
        }
        if(t)
            res.push_back(-p.size()+i+1);
    }
    return res;
}
};