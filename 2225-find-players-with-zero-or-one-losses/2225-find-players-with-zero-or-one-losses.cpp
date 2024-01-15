class Solution {
public:
vector<vector<int>> findWinners(vector<vector<int>>& matches) {
map<int,int>m;
    for (int i = 0; i < matches.size();++i) {
        m[matches[i][1]]++;
    }
    vector<vector<int>>ans(2);
    for (auto x:m) {
        if(x.second==1)
            ans[1].push_back(x.first);
    }
    set<int>s;
    for (int i = 0; i < matches.size(); ++i) {
        if(!m.count(matches[i][0]))
            s.insert(matches[i][0]);
    }
    for(auto x:s){
        ans[0].push_back(x);
    }
    return ans;
}
};