class Solution {
public:
    vector<int> parent;
    vector<int> sz;
    int maxSize; 
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
    maxSize=1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        maxSize=max(maxSize,sz[a]);
        return true;
    }
    return false;
}
struct Edge {
    int u, v, weight,ind;
    Edge(int u,int v,int w,int ind){
        this->u=u;
        this->v=v;
        this->weight=w;
        this->ind=ind;
    }

    bool operator<(Edge const& other) {
        return weight < other.weight;
    }

    bool operator==(Edge const&other){
        return (u==other.u&&v==other.v&&weight==other.weight);
    }
};


vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    parent.resize(n+1);
    sz.resize(n+1);
    vector<Edge> edge;
    for (int i=0;i<edges.size();i++) {
      edge.push_back(Edge(edges[i][0],edges[i][1],edges[i][2],i));
    }
    int cost = 0;
    for (int i = 0; i < n; i++)
        make_set(i);
    sort(edge.begin(), edge.end());
    for (Edge e : edge) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            union_sets(e.u, e.v);
        }
    }
    int m=edge.size();
    vector<vector<int>>ans(2);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            make_set(j);
        int curW = 0;
        for (int j = 0; j <m ; j++) {
            if (i != j && union_sets(edge[j].u, edge[j].v)) {
                curW += edge[j].weight;
            }
        }

        // If the graph is disconnected or the total weight is greater,
        // the edge is critical
        if (maxSize < n || curW > cost) {
            ans[0].push_back(edge[i].ind);
        } else {

            for (int j = 0; j < n; j++)
                make_set(j);
            union_sets(edge[i].u,edge[i].v);
            int newWeight = edge[i].weight;
            for (int j = 0; j < m; j++) {
                if (i != j && union_sets(edge[j].u,edge[j].v)) {
                    newWeight += edge[j].weight;
                }
            }

            // If total weight is the same, the edge is pseudo-critical
            if (newWeight == cost) {
                ans[1].push_back(edge[i].ind);
            }
        }
    }

    return ans;
}
};