class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
map<int,vector<int>>sz;
    for (int i = 0; i < groupSizes.size(); ++i) {
        sz[groupSizes[i]].push_back(i);
    }
    vector<vector<int>>ans;
    for (auto x:sz) {
        for (int i = 0; i < x.second.size()/x.first; ++i) {
            vector<int>cur;
            for (int j = i*x.first; j <(i+1)*x.first; ++j) {
                cur.push_back(x.second[j]);
            }
            ans.push_back(cur);
        }
    }
    return ans;
}
};