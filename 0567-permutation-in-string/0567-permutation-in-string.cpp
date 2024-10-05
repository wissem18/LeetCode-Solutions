class Solution {
public:
 bool checkInclusion(string s1, string s2) {
    if(s1.size()>s2.size())
        return false;
    vector<int> occ(26,0);
    for (int i = 0; i < s1.size(); ++i) {
        occ[s1[i]-'a']++;
    }
    int i=0;
    while(i<s2.size()){
        vector<int> occ2(26,0);
        int j=i;
        int nb=0;
        while(j<s2.size()&&occ2[s2[j]-'a']<occ[s2[j]-'a']&&occ[s2[j]-'a']){
            occ2[s2[j]-'a']++;
            j++;
            nb++;
            if(nb==s1.size())
                return true;
            }
        i++;
        }
    return false;
    }
};