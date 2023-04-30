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

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
vector<vector<int>>t1,t2,t3;
    for (int i = 0; i < edges.size(); ++i) {
        if(edges[i][0]==1)
            t1.push_back(edges[i]);
        if(edges[i][0]==2)
            t2.push_back(edges[i]);
        if(edges[i][0]==3)
            t3.push_back(edges[i]);
    }
  parent.resize(n+1);
    sz.resize(n+1);
    set<vector<int>>s;
  int nb1=0;
    for (int i = 0; i <= n; ++i) {
        make_set(i);
    }
    for (int i = 0; i < t3.size(); ++i) {
        if(find_set(t3[i][1])!=find_set(t3[i][2])){
            nb1++;
            union_sets(t3[i][1],t3[i][2]);
            s.insert(t3[i]);
        }
    }
    for (int i = 0; i < t1.size(); ++i) {
        if(find_set(t1[i][1])!=find_set(t1[i][2])){
            nb1++;
            union_sets(t1[i][1],t1[i][2]);
            s.insert(t1[i]);
        }
    }
    if(nb1!=n-1)
        return -1;


    int nb2=0;
    for (int i = 0; i <= n; ++i) {
        make_set(i);
    }
    for (int i = 0; i < t3.size(); ++i) {
        if(find_set(t3[i][1])!=find_set(t3[i][2])){
            nb2++;
            union_sets(t3[i][1],t3[i][2]);
        }
    }
    for (int i = 0; i < t2.size(); ++i) {
        if(find_set(t2[i][1])!=find_set(t2[i][2])){
            nb2++;
            union_sets(t2[i][1],t2[i][2]);
            s.insert(t2[i]);
        }
    }
    if(nb2!=n-1)
        return -1;
    return edges.size()-s.size();
}
};