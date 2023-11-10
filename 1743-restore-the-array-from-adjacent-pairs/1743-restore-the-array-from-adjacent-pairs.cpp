class Solution {
public:
map<int,vector<int>>adj;
vector<int>ans;
void dfs(int cur,int par=-1){
    ans.push_back(cur);
    for (auto c:adj[cur]) {
         if(c==par)continue;
         dfs(c,cur);
    }
}
vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {

map<int,int>occ;

    for (auto x:adjacentPairs) {
        occ[x[0]]++;
        occ[x[1]]++;
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    int cur = -1;
    for (auto x: occ) {
        if (x.second == 1) {
            cur = x.first;
            break;
        }
    }
    dfs(cur);
    return ans;
}
};