class Solution {
public:
vector<vector<int>> tree1, tree2;

void buildTree(vector<vector<int>> &tree, vector<vector<int>> &edges) {
    for (auto e: edges) {
        tree[e[0]].push_back(e[1]);
        tree[e[1]].push_back(e[0]);
    }
}

void dfs(int x, int d, vector<vector<int>> &tree, vector<bool> &vis, int &maxD, int &maxNode) {
    vis[x] = true;
    if (d > maxD) {
        maxD = d;
        maxNode = x;
    }
    for (auto child: tree[x]) {
        if (!vis[child])
            dfs(child, d + 1, tree, vis, maxD, maxNode);
    }
}

int Diameter(vector<vector<int>> &tree) {
    vector<bool> vis(1e5 + 1, false);
    int maxD = -1;
    int maxNode = 0;
    dfs(0, 0, tree, vis, maxD, maxNode);
    vis.assign(1e5 + 1, false);
    maxD = -1;
    dfs(maxNode, 0, tree, vis, maxD, maxNode);
    return maxD;
}

int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2) {
    tree1.resize(1e5 + 1);
    tree2.resize(1e5 + 1);
    buildTree(tree1, edges1);
    buildTree(tree2, edges2);
    int d1 = Diameter(tree1);
    int d2 = Diameter(tree2);
    int ans = max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    return ans;
}
};