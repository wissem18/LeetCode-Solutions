class Solution {
public:
    vector<int> parent;
vector<int> sz;
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
int ans;
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        ans--;
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
int n=isConnected.size();
parent.resize(n);
sz.resize(n);
ans=n;
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i==j)
                continue;
            if(isConnected[i][j]){
                union_sets(i,j);
            }
        }
    }
    return ans;
}
};