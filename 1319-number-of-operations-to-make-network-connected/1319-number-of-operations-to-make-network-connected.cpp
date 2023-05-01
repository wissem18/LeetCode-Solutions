class Solution {
public:
vector<int>parent;
vector<int>sz;
int nbcomp;
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        nbcomp--;
    }
}
int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size()<n-1)
        return -1;
    parent.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
   nbcomp=n;
    for (int i = 0; i < connections.size(); ++i) {
        union_sets(connections[i][0],connections[i][1]);
    }
    return nbcomp-1;
}
};