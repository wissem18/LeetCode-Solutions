class Solution {
public:
string frequencySort(string s) {
map<char,int>mp;
    for (int i = 0; i <s.size() ; ++i) {
        mp[s[i]]++;
    }
vector<pair<int,char>>a;
    for(auto x:mp){
        a.push_back({x.second,x.first});
    }
sort(a.rbegin(),a.rend());
    string ans="";
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].first; ++j) {
            ans+=a[i].second;
        }
    }  
    return ans;
}
};