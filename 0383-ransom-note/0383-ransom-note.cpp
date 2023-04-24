class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    map<char,int>occa;
    map<char,int>occb;
    for (int i = 0; i < ransomNote.size(); ++i) {
        occa[ransomNote[i]]++;
    }
    for (int i = 0; i < magazine.size(); ++i) {
        occb[magazine[i]]++;
    }
    for (auto x:occa) {
     if(occb.count(x.first)==0)
         return false;
     else if(occb[x.first]<x.second)
         return false;
    }
    return true;
}
};