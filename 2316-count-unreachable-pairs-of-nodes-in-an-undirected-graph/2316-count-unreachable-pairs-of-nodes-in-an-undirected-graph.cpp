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

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
 long long countPairs(int n, vector<vector<int>>& edges) {
    parent.resize(n);
    sz.resize(n);
     for (int i = 0; i < n; ++i) {
         make_set(i);
     }
     for (auto x:edges) {
         union_sets(x[0],x[1]);
     }
     set<int>s;
     long long ans=0;
     for (int i = 0; i < n; ++i) {
         int x= find_set(i);
         if(!s.count(x)){
             s.insert(x);
             ans+=sz[x]*1LL*(n-sz[x]);
         }
     }
     return ans/2;
    }
};