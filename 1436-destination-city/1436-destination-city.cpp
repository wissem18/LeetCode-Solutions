class Solution {
public:
string destCity(vector<vector<string>>& paths) {
map<string,int>mp;
    for (auto x:paths) {
       mp[x[0]]++;
       mp[x[1]]--;
    }
    for (auto x:mp) {
       if(x.second==-1)
           return x.first;
    }   
    return "";
}
};