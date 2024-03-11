class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>ord(26,26);
        for(int i=0;i<order.size();i++){
            ord[order[i]-'a']=i;
        }
    sort(s.begin(),s.end(),[&ord](char &a,char&b){return ord[a-'a']<ord[b-'a'];});    
    return s;
    }
};