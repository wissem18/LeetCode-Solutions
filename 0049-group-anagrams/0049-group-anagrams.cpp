class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
vector<vector<string>>ans;
vector<pair<string,int>>s;
    for (int i = 0; i < strs.size(); ++i) {
        string x=strs[i];
        sort(x.begin(),x.end());
        s.push_back({x,i});
    }
    sort(s.begin(),s.end());
    vector<string>tmp;
    tmp.push_back(strs[s[0].second]);
    for (int i =1; i < strs.size(); ++i) {
        if(s[i].first==s[i-1].first){
            tmp.push_back(strs[s[i].second]);
        }
        else{
            ans.push_back(tmp);
            tmp.clear();
            tmp.push_back(strs[s[i].second]);
        }
    }
    ans.push_back(tmp);
    return ans;
}
};