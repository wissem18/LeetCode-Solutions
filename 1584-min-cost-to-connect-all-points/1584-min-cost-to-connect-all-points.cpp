class Solution {
public:
    vector<int>parent;
vector<int>sz;
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
struct Edge {
int u, v, weight;
Edge(int u,int v,int w){
this->u=u;
this->v=v;
this->weight=w;
}

bool operator<(Edge const& other) {
return weight < other.weight;
}

bool operator==(Edge const&other){
return (u==other.u&&v==other.v&&weight==other.weight);
}
};

//in the main :

/*vector<Edge> edges;
int cost = 0;
vector<Edge> result;
for (int i = 0; i < n; i++)
make_set(i);
sort(edges.begin(), edges.end())
for (Edge e : edges) {
if (find_set(e.u) != find_set(e.v)) {
cost += e.weight;
result.push_back(e);
union_sets(e.u, e.v);
}
}*/
int minCostConnectPoints(vector<vector<int>>& points) {
int n=points.size();
parent.resize(n);
sz.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);
    vector<Edge> edges;
    for (int j = 0; j < n; ++j) {
        for (int k = j+1; k <n ; ++k) {
            edges.push_back(Edge(j,k,abs(points[j][0]-points[k][0])+abs(points[j][1]-points[k][1])));
        }
    }
    sort(edges.begin(),edges.end());
    int cost = 0;
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            union_sets(e.u, e.v);
        }
    }
    return cost;
}
};