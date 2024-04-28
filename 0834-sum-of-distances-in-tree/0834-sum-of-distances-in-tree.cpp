class Solution {
public:
vector<vector<int>> adj;
vector<int> sz;//counts subtree size
vector<int> ans;//counts sum of distance in subtree
void dfs1(int node, int par = -1) {
    for (auto c: adj[node]) {
        if (c == par)continue;
        dfs1(c, node);
        sz[node] += sz[c];
        ans[node] += ans[c] + sz[c];
    }
    sz[node]++;
}

void dfs2(int node, int &n,int par=-1) {
    for (auto c: adj[node]) {
        if (c == par)continue;
        ans[c]=ans[node]-sz[c]+(n-sz[c]);// the ans of the child node is the answer of its parent -its subtree size+ other nodes (because the ones in the subtree
        // will be closer to c by 1 from the parent and the ones that are not in same subtree as c will be further to c by 1 from the parent)
        dfs2(c,n,node);
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    adj.resize(n);
    for (auto e: edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    sz.assign(n,0);
    ans.assign(n,0);
    dfs1(0);
    dfs2(0,n);
    return ans;
}
};