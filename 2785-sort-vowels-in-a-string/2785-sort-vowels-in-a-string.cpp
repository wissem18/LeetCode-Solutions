class Solution {
public:
string sortVowels(string s) {
string vowels="aeuioAEUIO";
vector<pair<char,int>>v,u;
    for (int i=0;i<s.size();i++) {
         if(vowels.find(s[i])!=string::npos)
             v.push_back({s[i],i});
    }
    u=v;
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); ++i) {
        s[u[i].second]=v[i].first;
    }
    return s;
}
};